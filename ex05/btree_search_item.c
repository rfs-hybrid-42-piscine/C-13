/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 00:55:55 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/05 02:36:19 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

/**
 * @fn void *btree_search_item(t_btree *root, void *data_ref,
 * int (*cmpf)(void *, void *))
 * @brief Locates the first element matching a reference using infix traversal.
 * @details Recursively searches the left branch, then evaluates the current
 * node's item, and finally searches the right branch. Immediately returns
 * the payload upon the first match.
 * @param root A pointer to the root node of the tree.
 * @param data_ref The reference data to search for.
 * @param cmpf The comparison function to evaluate matches.
 * @return The matching item's void pointer, or NULL if not found.
 */
void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	void	*item;

	if (!root || !cmpf)
		return (NULL);
	item = btree_search_item(root->left, data_ref, cmpf);
	if (item)
		return (item);
	if (!cmpf(root->item, data_ref))
		return (root->item);
	item = btree_search_item(root->right, data_ref, cmpf);
	if (item)
		return (item);
	return (NULL);
}
