# 🟢 Exercise 06: btree_level_count

## 📝 Objective
Create a function `btree_level_count` which returns the size of the largest branch passed as an argument.

## 💡 The Logic
This requires purely mathematical recursion to determine depth.
1. **Base Case:** If the root is `NULL`, the depth is `0`.
2. **Branch Measurement:** We recursively call `btree_level_count` on both the left and right branches, storing their returned integer depths in separate variables.
3. **Evaluation:** We compare the two integers. Whichever is larger is the true depth of the sub-tree. We return that maximum value `+ 1` (to account for the current node itself) back up the recursive chain.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`btree_level_count.c`](btree_level_count.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-13` directory. You must pass the `-D EX06` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX06 ../tester.c btree_level_count.c -o test_ex06
   ./test_ex06
   ```
