/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:14:44 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/05 02:29:13 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/**
 * @fn void btree_apply_infix(t_btree *root, void (*applyf)(void *))
 * @brief Applies a function using infix (in-order) traversal.
 * @details Recursively visits the nodes in the order: Left -> Root -> Right.
 * If the tree is a Binary Search Tree (BST), this will process elements in
 * sorted ascending order.
 * @param root A pointer to the root node of the tree.
 * @param applyf The function to apply to each node's item.
 */
void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	btree_apply_infix(root->left, applyf);
	applyf(root->item);
	btree_apply_infix(root->right, applyf);
}
