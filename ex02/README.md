# 🟢 Exercise 02: btree_apply_infix

## 📝 Objective
Create a function `btree_apply_infix` which applies the function given as an argument to the item of each node, using infix traversal to traverse the tree.

## 💡 The Logic
Infix (also known as in-order) traversal processes the parent node *between* its children. If the tree is a Binary Search Tree (BST), this traversal perfectly reads the data in ascending sorted order!
1. **Null Check:** We verify the node and function pointers exist.
2. **Go Left:** We recursively call `btree_apply_infix` on the `left` child first, diving all the way down to the smallest values.
3. **Execution & Go Right:** Once returning from the left, we execute `applyf(root->item)`, and then recursively dive down the `right` branch.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`btree_apply_infix.c`](btree_apply_infix.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-13` directory. You must pass the `-D EX02` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX02 ../tester.c btree_apply_infix.c -o test_ex02
   ./test_ex02
   ```
