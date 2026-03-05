/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:55:10 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/05 02:29:00 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/**
 * @fn void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
 * @brief Applies a function using prefix (pre-order) traversal.
 * @details Recursively visits the nodes in the order: Root -> Left -> Right.
 * The function is applied to the parent node before traversing its children.
 * @param root A pointer to the root node of the tree.
 * @param applyf The function to apply to each node's item.
 */
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}
