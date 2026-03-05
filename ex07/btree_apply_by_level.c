/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:15:18 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/05 02:40:49 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/**
 * @fn static int process_and_count(t_btree **current_queue, int current_size,
 * int current_level, void (*applyf)(void *, int, int))
 * @brief Applies the function to the current queue and calculates the next
 * queue's size.
 * @details Iterates through the given array of nodes, applying the provided
 * function to each node's item. Simultaneously counts the total number of
 * non-NULL children across all nodes to accurately determine the memory
 * required for the next level's queue.
 * @param current_queue The array of node pointers for the current level.
 * @param current_size The number of elements in the current queue.
 * @param current_level The integer representation of the current depth level.
 * @param applyf The function to apply.
 * @return The required size for the subsequent queue.
 */
static int	process_and_count(t_btree **current_queue, int current_size,
	int current_level, void (*applyf)(void *, int, int))
{
	int	next_size;
	int	i;

	i = -1;
	next_size = 0;
	while (++i < current_size)
	{
		applyf(current_queue[i]->item, current_level, (i == 0));
		if (current_queue[i]->left)
			next_size++;
		if (current_queue[i]->right)
			next_size++;
	}
	return (next_size);
}

/**
 * @fn static t_btree **create_next_queue(t_btree **current_queue,
 * int current_size, int next_size)
 * @brief Allocates and populates an array with all children of the current
 * level.
 * @details Safely dynamically allocates a new array of pointers based on the
 * pre-calculated next_size. It then iterates through the current queue,
 * appending existing left and right child pointers sequentially into the new
 * array to form the next horizontal layer.
 * @param current_queue The array of node pointers for the current level.
 * @param current_size The number of elements in the current queue.
 * @param next_size The pre-calculated size required for the next queue.
 * @return An array containing pointers to all nodes in the next level.
 */
static t_btree	**create_next_queue(t_btree **current_queue, int current_size,
	int next_size)
{
	t_btree	**next_queue;
	int		i;
	int		j;

	next_queue = malloc(sizeof(t_btree *) * next_size);
	if (!next_queue)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < current_size)
	{
		if (current_queue[i]->left)
			next_queue[++j] = current_queue[i]->left;
		if (current_queue[i]->right)
			next_queue[++j] = current_queue[i]->right;
	}
	return (next_queue);
}

/**
 * @fn static void apply_level_handler(t_btree **current_queue,
 * int current_size, int current_level, void (*applyf)(void *, int, int))
 * @brief Orchestrates the recursive breadth-first traversal sequence.
 * @details Processes the current level, generates the queue for the next
 * level, safely frees the current memory block, and recurses downwards.
 * @param current_queue The array of node pointers for the current level.
 * @param current_size The number of elements in the current queue.
 * @param current_level The integer representation of the current depth level.
 * @param applyf The function to apply.
 */
static void	apply_level_handler(t_btree **current_queue, int current_size,
	int current_level, void (*applyf)(void *, int, int))
{
	t_btree	**next_queue;
	int		next_size;

	if (current_size == 0)
		return ;
	next_size = process_and_count(current_queue, current_size, current_level,
			applyf);
	if (next_size == 0)
	{
		free(current_queue);
		return ;
	}
	next_queue = create_next_queue(current_queue, current_size, next_size);
	free(current_queue);
	if (!next_queue)
		return ;
	apply_level_handler(next_queue, next_size, current_level + 1, applyf);
}

/**
 * @fn void btree_apply_by_level(t_btree *root,
 * void (*applyf)(void *item, int current_level, int is_first_elem))
 * @brief Applies a function traversing the tree level-by-level (Breadth-First).
 * @details Dynamically allocates an array-based queue starting with the root
 * node and leverages a recursive handler to process horizontal layers.
 * @param root A pointer to the root node of the tree.
 * @param applyf The complex function to apply.
 */
void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_btree	**queue;

	if (!root || !applyf)
		return ;
	queue = malloc(sizeof(t_btree *));
	if (!queue)
		return ;
	*queue = root;
	apply_level_handler(queue, 1, 0, applyf);
}
