/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 14:18:35 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/05 02:29:29 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/**
 * @fn void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
 * @brief Applies a function using suffix (post-order) traversal.
 * @details Recursively visits the nodes in the order: Left -> Right -> Root.
 * The function is applied to the parent node only after both its children
 * have been fully processed (essential for safely freeing trees).
 * @param root A pointer to the root node of the tree.
 * @param applyf The function to apply to each node's item.
 */
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}
