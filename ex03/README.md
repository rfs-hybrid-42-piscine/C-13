# 🟢 Exercise 03: btree_apply_suffix

## 📝 Objective
Create a function `btree_apply_suffix` which applies the function given as an argument to the item of each node, using suffix traversal to traverse the tree.

## 💡 The Logic
Suffix (also known as post-order) traversal processes the parent node *after* its children. This is the exact algorithm used when safely freeing a tree, as you cannot delete a parent until its child links are destroyed.
1. **Null Check:** We verify the node and function pointers exist.
2. **Dive Deep:** We recursively call `btree_apply_suffix` on the `left` child, then immediately on the `right` child.
3. **Execution:** Only after both child branches have been fully processed do we finally execute `applyf(root->item)` on the current node.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`btree_apply_suffix.c`](btree_apply_suffix.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-13` directory. You must pass the `-D EX03` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX03 ../tester.c btree_apply_suffix.c -o test_ex03
   ./test_ex03
   ```
