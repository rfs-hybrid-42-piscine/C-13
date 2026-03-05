# 🟢 Exercise 00: btree_create_node

## 📝 Objective
Create the function `btree_create_node` which allocates a new element. It should initialise its item to the value of the argument, and all other elements to 0.

## 💡 The Logic
This exercise establishes the foundational building block for all binary trees in this module.
1. **Memory Allocation:** We use `malloc` to dynamically allocate enough memory for a single `t_btree` structure.
2. **Data Initialization:** We assign the `item` pointer of the newly created struct to the argument provided.
3. **Safety & Hierarchy:** We explicitly set both the `left` and `right` pointers to `NULL` (or `0`) to signify that this node is a "leaf" with no current children.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`btree_create_node.c`](btree_create_node.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-13` directory. You must pass the `-D EX00` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -I . -D EX00 ../tester.c btree_create_node.c -o test_ex00
   ./test_ex00
   ```
