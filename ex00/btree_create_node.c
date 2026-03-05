/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 02:12:03 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/05 02:28:40 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/**
 * @fn t_btree *btree_create_node(void *item)
 * @brief Allocates and initializes a new binary tree node.
 * @details Safely reserves memory for a t_btree struct, assigns the provided
 * item payload, and initializes the left and right pointers to NULL to signify
 * it as a leaf node.
 * @param item A void pointer to the data to be stored in the node.
 * @return A pointer to the newly allocated tree node, or NULL if malloc fails.
 */
t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	if (!new)
		return (NULL);
	new->item = item;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
