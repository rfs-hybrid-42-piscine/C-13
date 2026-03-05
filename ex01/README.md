# 🟢 Exercise 01: btree_apply_prefix

## 📝 Objective
Create a function `btree_apply_prefix` which applies the function given as an argument to the item of each node, using prefix traversal to traverse the tree.

## 💡 The Logic
This introduces recursive tree traversal. Prefix (also known as pre-order) traversal processes the parent node *before* its children.
1. **Null Check:** We ensure both the current `root` and the function pointer `applyf` exist to prevent segmentation faults.
2. **Execution:** We immediately execute `applyf(root->item)` on the current node.
3. **Recursion:** We recursively call `btree_apply_prefix` on the `left` child branch, and then recursively call it on the `right` child branch.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`btree_apply_prefix.c`](btree_apply_prefix.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-13` directory. You must pass the `-D EX01` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX01 ../tester.c btree_apply_prefix.c -o test_ex01
   ./test_ex01
   ```
