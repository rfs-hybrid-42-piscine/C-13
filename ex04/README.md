# 🟢 Exercise 04: btree_insert_data

## 📝 Objective
Create a function `btree_insert_data` which inserts the element item into a tree. The tree passed as argument will be sorted: for each node, all lower elements are located on the left side, and all higher or equal elements are located on the right.

## 💡 The Logic
This converts a standard tree into a Binary Search Tree (BST) by routing data during insertion.
1. **Base Case (Empty Slot):** If the current pointer is `NULL`, we have found our insertion point. We spawn the new node here using `btree_create_node`.
2. **Comparison Routing:** If the node exists, we evaluate `cmpf((*root)->item, item)`.
3. **Recursive Navigation:** If the new item is strictly lower, we pass the left branch `&(*root)->left` recursively into our function. Otherwise, we pass the right branch. The recursion guarantees it will eventually hit a `NULL` leaf and spawn the node safely.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`btree_insert_data.c`](btree_insert_data.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-13` directory. You must pass the `-D EX04` flag to the compiler to selectively activate the test for this specific exercise! Because building a tree requires node creation, you must compile this alongside **[`btree_create_node.c`](ex00/btree_create_node.c)**!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX04 ../tester.c btree_insert_data.c ../ex00/btree_create_node.c -o test_ex04
   ./test_ex04
   ```
