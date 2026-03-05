*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-piscine-artwork/main/assets/covers/cover-c13.png" alt="C 13 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 C 13: Binary Trees</h1>
  <p><i>Mastering non-linear data structures, recursive traversals, and search algorithms.</i></p>
  
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <img src="https://img.shields.io/badge/Norminette-Passing-success" alt="Norminette badge" />
</div>

---

## 💡 Description
**C 13** introduces a powerful non-linear data structure: **The Binary Tree**. 

While linked lists restrict you to moving in one direction (to the `next` node), a binary tree node contains pointers to *two* child nodes: `left` and `right`. This module will teach you how to construct these hierarchical trees and navigate them using complex recursive traversal algorithms (Prefix, Infix, and Suffix). You will ultimately use these concepts to build and search a Binary Search Tree (BST).

Every exercise in this module relies on the custom `t_btree` structure defined in your `ft_btree.h` file:
```c
typedef struct s_btree
{
    struct s_btree  *left;
    struct s_btree  *right;
    void            *item;
}                   t_btree;
```

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise. It focuses on the fundamental logic of recursive C programming and hierarchical memory management.*

### 🔹 Creation & Traversals
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: btree_create_node`](ex00)** | **Node Instantiation:** Creating the building blocks of a tree. <br><br>**Logic:** Uses `malloc` to allocate memory for a single `t_btree` struct. It initializes its `item` to the value of the argument, and explicitly sets the `left` and `right` pointers to `0` (or `NULL`) to signify it is a leaf node. |
| **[`ex01: btree_apply_prefix`](ex01)** | **Prefix Traversal (Pre-order):** Visiting the parent node *before* its children. <br><br>**Logic:** Uses recursion to traverse the tree. It first applies the function to the current node's `item`, then recursively calls itself on the `left` child, and finally on the `right` child. |
| **[`ex02: btree_apply_infix`](ex02)** | **Infix Traversal (In-order):** Visiting the parent node *between* its children. <br><br>**Logic:** Recursively traverses the tree. It calls itself on the `left` child first, then applies the function to the current node's `item`, and finally calls itself on the `right` child. (In a BST, this processes elements in sorted ascending order!) |
| **[`ex03: btree_apply_suffix`](ex03)** | **Suffix Traversal (Post-order):** Visiting the parent node *after* its children. <br><br>**Logic:** Recursively traverses the tree. It calls itself on the `left` child, then the `right` child, and only applies the function to the current node's `item` at the very end. (This is essential for safely freeing a tree!) |

### 🔍 Search & Modification
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex04: btree_insert_data`](ex04)** | **Binary Search Tree (BST) Construction:** Inserting elements while maintaining strict sorting rules. <br><br>**Logic:** Compares the new `item` with the current node's `item` using the `cmpf` function. If it is strictly lower, it routes to the `left` branch; if it is higher or equal, it routes to the `right`. If the target branch is `NULL`, it spawns the new node there using `btree_create_node`. |
| **[`ex05: btree_search_item`](ex05)** | **Infix Searching:** Finding specific data within the tree structure. <br><br>**Logic:** Browses the tree using infix traversal (Left -> Node -> Right). Evaluates each `item` against `data_ref`. The moment it finds a match, it returns the node's item. If it finishes traversing without a match, it returns `NULL`. |

### 👑 Advanced Tree Metrics & BFS
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex06: btree_level_count`](ex06)** | **Tree Depth Calculation:** Finding the longest path from the root to a leaf. <br><br>**Logic:** A purely recursive mathematical function. It returns the size of the largest branch by calculating `1 + MAX(btree_level_count(left), btree_level_count(right))`. |
| **[`ex07: btree_apply_by_level`](ex07)** | **Breadth-First Search (BFS):** Traversing the tree horizontally, level by level. <br><br>**Logic:** The most complex exercise in the Piscine. Unlike depth-first recursion (prefix/infix/suffix), BFS requires keeping track of horizontal layers. The function passed takes three arguments: the item, the current level, and a flag indicating if it's the first node of that level. It often requires calculating the total depth first, then using a recursive helper function to apply the function to nodes at a specific target depth. |

---

## 🛠️ Instructions

### 🧪 Compilation & Testing
Testing binary trees requires you to manually link tree nodes in a **[`tester.c`](tester.c)** file. 

Just like C 12, to avoid "undefined reference" errors, the **[`tester.c`](tester.c)** file in the root directory uses **C Preprocessor Macros** (`#ifdef`). This allows you to selectively compile and test only the exercises you want.

> **Important Setup Note:** Because **[`ft_btree.h`](ex00/ft_btree.h)** must be included in each individual exercise folder (and generally forbidden from being turned in at the root), you must use the `-I ex00` compiler flag when testing from the root so the compiler knows where to find your structure!

1. **Clone the repository:**
   You can clone this module directly, or pull the entire 42 Piscine parent repository which includes this module as a submodule.

   **Option A: Clone this module directly**
   ```bash
   git clone git@github.com:rfs-hybrid-42-piscine/C-13.git C-13
   cd C-13
   ```

   **Option B: Clone the parent repository (with submodules)**
   ```bash
   git clone --recurse-submodules git@github.com:rfs-hybrid/42-Piscine.git 42-Piscine
   cd 42-Piscine/C-13
   ```

2. **Test a Single Exercise:**
   Pass the corresponding `-D EX**` flag to activate that specific test block inside **[`tester.c`](tester.c)**. Note that testing traversal functions requires you to compile your **[`btree_create_node.c`](ex00/btree_create_node.c)** function alongside them so the tester can build the tree!
   ```bash
   # Example for ex01 (requires ex00 to create the tree):
   cc -Wall -Wextra -Werror -I ex00 -D EX01 tester.c ex00/btree_create_node.c ex01/btree_apply_prefix.c -o test_ex01
   ./test_ex01
   ```

3. **Test Multiple Exercises Together:**
   You can chain multiple `-D` flags to test several functions at once, provided you include all their `.c` files in the command.
   ```bash
   # Example for traversals:
   cc -Wall -Wextra -Werror -I ex00 -D EX01 -D EX02 -D EX03 tester.c ex00/btree_create_node.c ex01/btree_apply_prefix.c ex02/btree_apply_infix.c ex03/btree_apply_suffix.c -o test_multiple
   ./test_multiple
   ```

4. **Test ALL Exercises at Once:**
   By passing the `-D TEST_ALL` master flag, you can activate the entire testing suite in one go!
   ```bash
   cc -Wall -Wextra -Werror -I ex00 -D TEST_ALL tester.c ex00/*.c ex01/*.c ex02/*.c ... -o test_all
   ./test_all
   ```

> **⚠️ WARNING for 42 Students:** Do not push **[`tester.c`](tester.c)** or any executable files to your final Moulinette repository! They are strictly for local testing purposes. Submitting unauthorized files will result in a 0.

### 🚨 The Norm
Moulinette relies on a program called `norminette` to check if your files comply with the Norm. Every single `.c` and `.h` file must pass.

**The 42 Header:**
Before writing any code, every file must start with the standard 42 header. `norminette` will automatically fail any file missing this specific signature.
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 02:12:03 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/05 02:28:40 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

Run the following command before pushing:
```bash
norminette -R CheckForbiddenSourceHeader <file.c>
```

---

## 📚 Resources & References

* [GeeksforGeeks: Binary Trees](https://www.geeksforgeeks.org/binary-tree-data-structure/) - Excellent visual guide for understanding binary tree structures.
* [Tree Traversals (Inorder, Preorder and Postorder)](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/) - Deep dive into how recursive traversals process nodes.
* [42 Norm V4](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf) - The strict coding standard for 42 C projects.

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All C functions were built manually to strictly comply with the 42 Norm and deeply understand manual memory manipulation, enforcing the concept that learning is about developing the ability to find an answer, not just getting one directly.
* **Documentation:** AI tools were utilized to structure this `README.md` and format the logic breakdowns to create a clean, accessible educational resource for fellow 42 students.
