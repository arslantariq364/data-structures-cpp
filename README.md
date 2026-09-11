# ⚡ Core Data Structures & Algorithms in C++

[![C++17](https://img.shields.io/badge/C%2B%2B-17-00599C.svg?logo=c%2B%2B&logoColor=white)](#)
[![Data Structures](https://img.shields.io/badge/Topics-DSA%20%7C%20Algorithms-orange.svg)](#)
[![Complexity](https://img.shields.io/badge/Performance-Big--O%20Optimized-brightgreen.svg)](#)
[![FAST NUCES](https://img.shields.io/badge/Coursework-FAST%20NUCES-red.svg)](#)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

> A rigorous collection of fundamental Data Structures and Algorithmic paradigms implemented from first principles in modern C++, featuring self-balancing trees, linear collections, dynamic memory allocation, and recursive problem solving.

---

## 📊 Comprehensive Time & Space Complexity Reference

| Data Structure / Module | Access (Avg / Worst) | Search (Avg / Worst) | Insertion (Avg / Worst) | Deletion (Avg / Worst) | Auxiliary Space |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **AVL Tree (Self-Balancing)** | $\mathcal{O}(\log n)$ | $\mathcal{O}(\log n)$ | $\mathcal{O}(\log n)$ | $\mathcal{O}(\log n)$ | $\mathcal{O}(n)$ |
| **Binary Search Tree (BST)** | $\mathcal{O}(\log n) / \mathcal{O}(n)$ | $\mathcal{O}(\log n) / \mathcal{O}(n)$ | $\mathcal{O}(\log n) / \mathcal{O}(n)$ | $\mathcal{O}(\log n) / \mathcal{O}(n)$ | $\mathcal{O}(n)$ |
| **Singly Linked List** | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ (Head) / $\mathcal{O}(n)$ | $\mathcal{O}(1)$ (Head) / $\mathcal{O}(n)$ | $\mathcal{O}(n)$ |
| **Doubly Linked List** | $\mathcal{O}(n)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ (Head/Tail) | $\mathcal{O}(1)$ (with node pointer) | $\mathcal{O}(n)$ |
| **Array & Dynamic Queue** | $\mathcal{O}(1)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ (Enqueue) | $\mathcal{O}(1)$ (Dequeue) | $\mathcal{O}(n)$ |
| **Dynamic Array Stack** | $\mathcal{O}(1)$ | $\mathcal{O}(n)$ | $\mathcal{O}(1)$ (Push) | $\mathcal{O}(1)$ (Pop) | $\mathcal{O}(n)$ |
| **Recursive Subset Generator**| — | — | $\mathcal{O}(2^n)$ (Generation) | — | $\mathcal{O}(n)$ (Call Stack) |

---

## 🌳 Module Breakdown

### 1. Self-Balancing AVL Tree (`24P-0610_AVLTREE.cpp`)
Maintains a strict balance factor $BF = \text{height}(left) - \text{height}(right) \in \{-1, 0, +1\}$.
- **Rotations:** Full support for Left-Left (LL), Right-Right (RR), Left-Right (LR), and Right-Left (RL) rotations.
- **Features:** Node insertion with automatic height updating, rebalancing passes, in-order, pre-order, and level-order traversals.

### 2. Binary Search Tree (`24P-0610_BST.cpp`)
Hierarchical binary search tree supporting recursive and iterative operations:
- Recursive search, minimum/maximum node extraction.
- Three-case node deletion (leaf node, single-child node, two-child node using in-order successor).
- Tree height calculation and leaf count computation.

### 3. Linked Lists (`24P-0610_SINGLYLINKLIST.cpp` & `24P-0610_DOUBLYLINKLIST.cpp`)
Pointer-based dynamic list implementations:
- **Singly Linked:** Node insertion at head/tail/k-th position, deletion by value, reversal, and cycle detection.
- **Doubly Linked:** Bidirectional node linkage with `prev` and `next` pointers, forward and backward list traversals, and $O(1)$ head/tail operations.

### 4. Queue Implementations (`24P-0610_QUEUE.cpp`)
- Linear Array Queue with boundary checking.
- Circular Queue utilizing modulo indexing (`(rear + 1) % size`) to prevent capacity drift.
- Queue state inspectors: `isEmpty()`, `isFull()`, `front()`, and element counting.

### 5. Stack Implementations (`24P-0610_STACKS.cpp`)
- Dynamic Array Stack with LIFO ordering.
- Expression evaluation algorithms: Parentheses balancing, Infix to Postfix conversion, and Postfix expression evaluation.

### 6. Recursion & Backtracking (`24P-0610_RECURSION.cpp`)
- Power set / subset generation via inclusion-exclusion branch recursion.
- Permutation generation, factorial, and recursive divide-and-conquer solutions.

---

## 🛠️ Compilation & Execution Guide

All modules are written in standard C++ and compile with any standard C++17 compatible compiler (`g++`, `clang++`, or MSVC).

### Compile with GCC:
```bash
# Example: Compile AVL Tree
g++ -std=c++17 -Wall -Wextra -O2 24P-0610_AVLTREE.cpp -o avl_tree
./avl_tree

# Example: Compile BST
g++ -std=c++17 -Wall -Wextra -O2 24P-0610_BST.cpp -o bst
./bst

# Example: Compile Doubly Linked List
g++ -std=c++17 -Wall -Wextra -O2 24P-0610_DOUBLYLINKLIST.cpp -o doubly_list
./doubly_list
```

---

## 📂 Source Code Catalog

```text
├── 24P-0610_AVLTREE.cpp          # AVL Tree with LL/RR/LR/RL Rotations
├── 24P-0610_BST.cpp              # Binary Search Tree with 3-case deletion
├── 24P-0610_DOUBLYLINKLIST.cpp   # Bidirectional Doubly Linked List
├── 24P-0610_SINGLYLINKLIST.cpp   # Singly Linked List with reversals
├── 24P-0610_QUEUE.cpp            # Array & Circular FIFO Queues
├── 24P-0610_STACKS.cpp           # LIFO Stack & Infix/Postfix algorithms
├── 24P-0610_RECURSION.cpp        # Combinatorial & Backtracking Recursion
├── LICENSE                       # MIT License
└── README.md                     # Comprehensive documentation
```

---

## 👨‍💻 Author

**Arslan Tariq**  
*Computer Science Undergraduate @ FAST NUCES*  
*Applied Physics Teaching Assistant*  
[GitHub Profile](https://github.com/arslantariq364)

---

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
