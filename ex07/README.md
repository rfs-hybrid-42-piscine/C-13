# 🟢 Exercise 07: btree_apply_by_level

## 📝 Objective
Create a function `btree_apply_by_level` which applies the function passed as an argument to each node of the tree. The tree must be browsed level by level.

## 💡 The Logic
This is a Breadth-First Search (BFS) implementation. Standard depth-first recursions (prefix, infix) cannot process a tree horizontally.
1. **The Queue System:** BFS requires a queue. To comply with the strict 42 Norm (which makes dynamic linked-list queues difficult), we use an array of `t_btree` pointers dynamically sized for the current level.
2. **Processing a Level:** We iterate through the current array, applying `applyf` to each node. Simultaneously, we count how many non-NULL child nodes they possess.
3. **Generating the Next Level:** Using the child count, we `malloc` a new array for the *next* level, populate it with all the left and right children we find, free the old queue, and recurse to process the newly built level array.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`btree_apply_by_level.c`](btree_apply_by_level.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-13` directory. You must pass the `-D EX07` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX07 ../tester.c btree_apply_by_level.c -o test_ex07
   ./test_ex07
   ```
