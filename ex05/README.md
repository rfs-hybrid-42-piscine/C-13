# 🟢 Exercise 05: btree_search_item

## 📝 Objective
Create a function `btree_search_item` which returns the first element related to the reference data given as an argument. The tree should be traversed using infix traversal. If the element isn't found, the function should return NULL.

## 💡 The Logic
We are building a search algorithm bound to the strict infix traversal rules.
1. **Left Branch Search:** We recursively call the search on the `left` branch. If that call returns a match, we immediately return it upward to break the recursion.
2. **Root Check:** If the left branch yielded nothing, we evaluate the current node: `cmpf(root->item, data_ref)`. If it returns `0`, we have our match and return `root->item`.
3. **Right Branch Search:** If the root wasn't a match either, we finally recurse down the `right` branch and return whatever it finds (a matching item or `NULL`).

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`btree_search_item.c`](btree_search_item.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-13` directory. You must pass the `-D EX05` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX05 ../tester.c btree_search_item.c -o test_ex05
   ./test_ex05
   ```
