/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:40:10 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/05 02:38:20 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>

/**
 * @struct s_btree
 * @brief The standard 42 binary tree node structure.
 * @details Contains a generic void pointer for data payload and pointers 
 * to the left and right child nodes in the hierarchy.
 * @param left A pointer to the left child branch (strictly smaller elements in
 * a BST).
 * @param right A pointer to the right child branch (greater or equal elements
 * in a BST).
 * @param item A generic void pointer storing the node's data payload.
 */
typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;

t_btree	*btree_create_node(void *item);

#endif
