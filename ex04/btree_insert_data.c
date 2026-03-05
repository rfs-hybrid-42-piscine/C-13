/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:45:55 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/05 02:35:19 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/**
 * @fn void btree_insert_data(t_btree **root, void *item,
 * int (*cmpf)(void *, void *))
 * @brief Inserts an element into a Binary Search Tree (BST).
 * @details Routes the new item dynamically. Lower elements are recursively
 * assigned to the left branch, while higher or equal elements are routed to
 * the right branch, maintaining a strictly sorted hierarchy.
 * @param root A double pointer to the root node of the tree.
 * @param item The data payload to be inserted.
 * @param cmpf The comparison function used to evaluate element hierarchy.
 */
void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	t_btree	*new;

	if (!root || !cmpf)
		return ;
	if (!*root)
	{
		new = btree_create_node(item);
		if (!new)
			return ;
		*root = new;
		return ;
	}
	if (cmpf((*root)->item, item) > 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}
