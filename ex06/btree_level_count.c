/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:23:58 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/05 02:36:39 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/**
 * @fn int btree_level_count(t_btree *root)
 * @brief Calculates the depth of the largest branch in the tree.
 * @details Uses mathematical recursion to traverse all branches, comparing
 * the depth of the left and right sides and returning the maximum value plus
 * one (to account for the current node).
 * @param root A pointer to the root node of the tree.
 * @return The integer representing the maximum tree depth.
 */
int	btree_level_count(t_btree *root)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	left = btree_level_count(root->left);
	right = btree_level_count(root->right);
	if (left >= right)
		return (left + 1);
	return (right + 1);
}
