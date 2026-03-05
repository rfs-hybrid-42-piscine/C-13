/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 02:47:17 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/05 02:47:19 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_btree.h"

/* --- Master Switch --- */
#ifdef TEST_ALL
# define EX00
# define EX01
# define EX02
# define EX03
# define EX04
# define EX05
# define EX06
# define EX07
#endif

/* --- Prototypes --- */
t_btree	*btree_create_node(void *item);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int		btree_level_count(t_btree *root);
void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));

/* --- Custom Helper Functions for Testing --- */
t_btree	*build_test_node(char *item)
{
	t_btree *new = malloc(sizeof(t_btree));
	new->item = item;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/* Builds a balanced BST: 
        4
      /   \
     2     6
    / \   / \
   1   3 5   7
*/
t_btree	*build_test_tree(void)
{
	t_btree *root = build_test_node("4");
	root->left = build_test_node("2");
	root->right = build_test_node("6");
	root->left->left = build_test_node("1");
	root->left->right = build_test_node("3");
	root->right->left = build_test_node("5");
	root->right->right = build_test_node("7");
	return (root);
}

void	print_str(void *item)
{
	printf("[%s] ", (char *)item);
}

int		cmp_str(void *s1, void *s2)
{
	return (strcmp((char *)s1, (char *)s2));
}

void	print_level_node(void *item, int current_level, int is_first_elem)
{
	if (is_first_elem)
		printf("\nLevel %d: ", current_level);
	printf("[%s] ", (char *)item);
}

void	local_print_infix(t_btree *root)
{
	if (!root)
		return ;
	local_print_infix(root->left);
	printf("[%s] ", (char *)root->item);
	local_print_infix(root->right);
}

/* --- Main Testing Function --- */
int	main(void)
{
#ifdef EX00
	printf("--- EX00: btree_create_node ---\n");
	t_btree *node = btree_create_node("RootNode");
	printf("Expected: Item: RootNode | Left: NULL | Right: NULL\nResult  : ");
	if (node)
	{
		printf("Item: %s | Left: %s | Right: %s\n", 
			(char *)node->item, 
			node->left ? "ERR" : "NULL", 
			node->right ? "ERR" : "NULL");
		free(node);
	}
	printf("\n");
#endif

#ifdef EX01
	printf("--- EX01: btree_apply_prefix ---\n");
	t_btree *tree1 = build_test_tree();
	printf("Expected: [4] [2] [1] [3] [6] [5] [7] \nResult  : ");
	btree_apply_prefix(tree1, print_str);
	printf("\n\n");
#endif

#ifdef EX02
	printf("--- EX02: btree_apply_infix ---\n");
	t_btree *tree2 = build_test_tree();
	printf("Expected: [1] [2] [3] [4] [5] [6] [7] \nResult  : ");
	btree_apply_infix(tree2, print_str);
	printf("\n\n");
#endif

#ifdef EX03
	printf("--- EX03: btree_apply_suffix ---\n");
	t_btree *tree3 = build_test_tree();
	printf("Expected: [1] [3] [2] [5] [7] [6] [4] \nResult  : ");
	btree_apply_suffix(tree3, print_str);
	printf("\n\n");
#endif

#ifdef EX04
	printf("--- EX04: btree_insert_data ---\n");
	t_btree *tree4 = NULL;
	/* Note: This relies on btree_create_node being compiled */
	btree_insert_data(&tree4, "4", cmp_str);
	btree_insert_data(&tree4, "2", cmp_str);
	btree_insert_data(&tree4, "6", cmp_str);
	btree_insert_data(&tree4, "1", cmp_str);
	btree_insert_data(&tree4, "3", cmp_str);
	btree_insert_data(&tree4, "5", cmp_str);
	btree_insert_data(&tree4, "7", cmp_str);
	printf("Expected (Infix Order): [1] [2] [3] [4] [5] [6] [7] \nResult                : ");
	local_print_infix(tree4);
	printf("\n\n");
#endif

#ifdef EX05
	printf("--- EX05: btree_search_item ---\n");
	t_btree *tree5 = build_test_tree();
	void *found = btree_search_item(tree5, "5", cmp_str);
	void *not_found = btree_search_item(tree5, "9", cmp_str);
	printf("Search '5' Expected: 5    | Result: %s\n", found ? (char *)found : "NULL");
	printf("Search '9' Expected: NULL | Result: %s\n\n", not_found ? (char *)not_found : "NULL");
#endif

#ifdef EX06
	printf("--- EX06: btree_level_count ---\n");
	t_btree *tree6 = build_test_tree();
	
	t_btree *linear = build_test_node("A");
	linear->left = build_test_node("B");
	linear->left->left = build_test_node("C");
	linear->left->left->left = build_test_node("D");

	printf("Balanced BST Expected Depth: 3 | Result: %d\n", btree_level_count(tree6));
	printf("Linear Tree Expected Depth : 4 | Result: %d\n\n", btree_level_count(linear));
#endif

#ifdef EX07
	printf("--- EX07: btree_apply_by_level ---\n");
	t_btree *tree7 = build_test_tree();
	printf("Expected Output:\nLevel 0: [4] \nLevel 1: [2] [6] \nLevel 2: [1] [3] [5] [7] \n\nResult:");
	btree_apply_by_level(tree7, print_level_node);
	printf("\n\n");
#endif

	return (0);
}
