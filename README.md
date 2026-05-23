<p align="center">
  <img src="https://img.shields.io/badge/Language-C++-blue?style=for-the-badge&logo=cplusplus&logoColor=white" />
  <img src="https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge" />
  <img src="https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge" />
</p>

<h1 align="center">🧠 DSA-Basics</h1>

<p align="center">
  A structured, continuously evolving repository of <strong>Data Structures & Algorithms</strong> implementations in <strong>C++</strong> — built for competitive programming, technical interviews, and deep conceptual understanding.
</p>

---

## 📌 Objectives

- Build strong foundational understanding of core DSA concepts
- Implement data structures and algorithms **from scratch**
- Solve problems from competitive programming platforms (Codeforces, LeetCode, CSES, SPOJ, AtCoder, HackerEarth)
- Maintain clean, well-commented, and efficient code
- Track progress and serve as a personal knowledge base

---

## 📂 Repository Structure

```
DSA-Basics/
│
├── Binary Tree/              # Binary tree construction & traversals
├── Combinatorics/            # nCr, Stars & Bars, modular arithmetic
├── Dynamic Programming/      # Grid DP, bitmask DP, state optimization
├── Git Commads/              # Git & GitHub quick-reference (PDF)
├── Graph/                    # BFS, DFS, Dijkstra's shortest path
├── Greedy Algorithms/        # Kadane's algorithm (linear & circular)
├── Infix-Postfix-Prefix/     # Expression conversion with theory notes
├── Linked List/              # Singly, Doubly, and Circular linked lists
├── PBDS/                     # Policy-Based Data Structures (GNU)
├── Searching/                # Ternary search (real & integer variants)
├── Segment Tree/             # Segment Tree & Lazy Propagation templates
├── Segmented Sieve/          # Prime counting & range-based sieve
├── Sorting Algorithms/       # Bubble, Selection, Insertion, Merge Sort
├── Stack/                    # Stack via Array, Vector, and Linked List
├── String Hashing/           # Polynomial hashing & prefix hash (double hash)
├── Tree/                     # DFS, BFS, Height, Binary Lifting, LCA
└── README.md
```

---

## 🗂️ Topics & Contents

### 1. Binary Tree

| File | Description | Key Operations |
|------|-------------|----------------|
| `Basic.cpp` | Full binary tree implementation from scratch | Build from preorder, Pre/In/Post/Level-order traversal, Line-by-line level-order, Height, Node count |

---

### 2. Combinatorics

| File | Description | Complexity |
|------|-------------|------------|
| `nCr.cpp` | nCr with precomputed factorials & modular inverse (Fermat's little theorem) | Precompute: `O(N log MOD)`, Query: `O(1)` |
| `nCr_Trick.cpp` | nCr **without modular arithmetic** — fits in `long long` | `O(min(r, n-r))` |
| `StarsAndBars.cpp` | Stars and Bars combinatorics technique | `O(min(r, n-r))` |

> **Problems**: [K-Special Cells (HackerEarth)](https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/shinos-k-special-cells-c8538ebb/), [Unique Paths (LeetCode)](https://leetcode.com/problems/unique-paths/description/), [Marbles (SPOJ)](https://www.spoj.com/problems/MARBLES/)

---

### 3. Dynamic Programming

| File | Description | Technique |
|------|-------------|-----------|
| `MinimumSumPath.cpp` | Minimum Path Sum — 3 different approaches (top-down, bottom-up, iterative) | Grid DP, Memoization |
| `AnswerConstruction.cpp` | Path reconstruction from DP table (2 methods) | Answer tracing via DP |
| `State-Transition-Time-Space-Optimization.cpp` | Space-optimized DP using 1D arrays instead of 2D | Space optimization |
| `Cycling-DP-States.cpp` | Expected value DP with cycling states | Probability DP |
| `Dima-and-a-Bad-XOR.cpp` | Bitmask DP with answer construction | Bitmask DP |
| `RectangleCutting.cpp` | Minimum cuts to divide rectangle into squares | Interval DP |
| `RoadOptimization..cpp` | Road optimization with constraints | Multi-dimensional DP |

> **Problems**: [Min Path Sum (LeetCode)](https://leetcode.com/problems/minimum-path-sum/description/), [J-Sushi (AtCoder DP)](https://atcoder.jp/contests/dp/tasks/dp_j), [Dima and a Bad XOR (Codeforces)](https://codeforces.com/problemset/problem/1151/B), [Rectangle Cutting (CSES)](https://cses.fi/problemset/task/1744/), [Road Optimization (Codeforces)](https://codeforces.com/contest/1625/problem/C)

---

### 4. Graph

| File | Description | Complexity |
|------|-------------|------------|
| `BFS.cpp` | Breadth-First Search on an undirected graph | `O(V + E)` |
| `DFS.cpp` | Depth-First Search on an undirected graph | `O(V + E)` |
| `Dijkstra.cpp` | Single-Source Shortest Path with path reconstruction (priority queue + set-based variants) | `O((V + E) log V)` |

---

### 5. Greedy Algorithms

| File | Description |
|------|-------------|
| `Kadanes-Algo-Linear&Circular.cpp` | Kadane's Algorithm for **Maximum Subarray Sum** — handles both linear and circular arrays |

> **Problem**: [Maximum Sum Circular Subarray (LeetCode)](https://leetcode.com/problems/maximum-sum-circular-subarray/description/)

---

### 6. Infix-Postfix-Prefix

| File | Description |
|------|-------------|
| `BasicKnowledge.txt` | Detailed theory: why postfix/prefix exist, how CPU evaluates expressions, conversion rules with examples |
| `InfixToPostfix.cpp` | Stack-based Infix → Postfix conversion with operator precedence |
| `InfixToPrefix.cpp` | Stack-based Infix → Prefix conversion (reverse, convert, reverse) |

---

### 7. Linked List

| File | Description | Key Operations |
|------|-------------|----------------|
| `SinglyLinkedList.cpp` | Complete singly linked list with advanced operations | Push/Pop (front & back), Insert at index, Search, Reverse, Middle element (Floyd's), Cycle detection, Cycle start detection, Cycle removal, Merge two sorted lists |
| `DoublyLinkedList.cpp` | Doubly linked list with bidirectional traversal | Push/Pop (front & back), Print |
| `CircularLinkedList.cpp` | Circular linked list maintaining tail→head circularity | Insert/Delete at head & tail, Circular print |

---

### 8. PBDS (Policy-Based Data Structures)

| File | Description |
|------|-------------|
| `Basics.cpp` | Sliding Window Median using GNU `__gnu_pbds::tree` — O(log n) `find_by_order()` and `order_of_key()`. Includes comparison with multiset-based approach. |

> **Problem**: [Sliding Window Median (CSES)](https://cses.fi/problemset/task/1076/)

---

### 9. Searching

| File | Description | Complexity |
|------|-------------|------------|
| `TernarySearch.cpp` | Ternary Search for unimodal functions — both **real-valued** (`long double`, epsilon-based) and **integer** variants | `O(log n)` |

---

### 10. Segment Tree

| File | Description | Complexity |
|------|-------------|------------|
| `SegmentTree.cpp` | Generic **Segment Tree template** with customizable `Node` and `Update` classes | Build: `O(n)`, Update: `O(log n)`, Query: `O(log n)` |
| `LazySegmentTree.cpp` | **Lazy Propagation Segment Tree** template with range updates and range queries | Build: `O(n)`, Update: `O(log n)`, Query: `O(log n)` |

> Both templates are designed to be **reusable** — just modify the `Node`, `Update`, `merge()`, and `apply()` methods for different problems.

---

### 11. Segmented Sieve

| File | Description | Complexity |
|------|-------------|------------|
| `CountingPrimes.cpp` | Count all primes from 1 to N using **Segmented Sieve of Eratosthenes** | `O(N log log N)` |
| `RangeBasedSieve.cpp` | Find all primes in range `[L, R]` using segmented sieve | `O((R-L) log R + √R)` |

> **Problem**: [PRINT (SPOJ)](https://www.spoj.com/problems/PRINT/)

---

### 12. Sorting Algorithms

| File | Algorithm | Time Complexity | Space |
|------|-----------|-----------------|-------|
| `BubbleSort.cpp` | Bubble Sort (with early termination optimization) | Best: `O(n)`, Worst: `O(n²)` | `O(1)` |
| `SelectionSort.cpp` | Selection Sort | `O(n²)` | `O(1)` |
| `InsertionSort.cpp` | Insertion Sort | Best: `O(n)`, Worst: `O(n²)` | `O(1)` |
| `MergeSort.cpp` | Merge Sort (divide & conquer) | `O(n log n)` | `O(n)` |

> All sorting implementations include detailed inline explanations and dry-run comments.

---

### 13. Stack

| File | Description |
|------|-------------|
| `StackUsingArray.cpp` | Stack implementation using a **static array** with overflow handling |
| `StackUsingVector.cpp` | Stack implementation using `std::vector` (dynamic array) |
| `StackUsingLinkedList.cpp` | Stack implementation using `std::list` (doubly linked list) |

---

### 14. String Hashing

| File | Description |
|------|-------------|
| `HashFunction.cpp` | Polynomial hash function + **Double Hashing** (two bases, two mods) for collision resistance |
| `PrefixHash.cpp` | **Prefix Hash** class for O(1) substring hash queries — uses modular exponentiation & precomputed inverse powers |

> **Problem**: [NHAY — A Needle in the Haystack (SPOJ)](https://www.spoj.com/problems/NHAY/)

---

### 15. Tree

| File | Description | Technique |
|------|-------------|-----------|
| `BFS.cpp` | Level-order traversal on a generic tree (parent tracking) | BFS |
| `DFS.cpp` | DFS with **enter/exit timestamps** for subtree queries | Euler tour |
| `Height.cpp` | Tree height computation using both DFS and BFS | Level counting |
| `BinaryLifting.cpp` | **Binary Lifting** — find the k-th ancestor in `O(log n)` per query | Sparse table on ancestors |
| `LCA.cpp` | **Lowest Common Ancestor** using Binary Lifting | `O(log n)` per query |

---

## 💻 Language & Tools

| | |
|---|---|
| **Language** | C++ (with `bits/stdc++.h` and GNU extensions) |
| **Compiler** | g++ (MinGW / GCC) |
| **Extensions** | `pb_ds` (Policy-Based Data Structures) |
| **IDE** | Visual Studio Code |
| **Platforms** | Codeforces, LeetCode, CSES, SPOJ, AtCoder, HackerEarth |

---

## 🚀 How to Use

### Compile & Run any file

```bash
g++ -o output filename.cpp -std=c++17
./output
```

### Example

```bash
cd "Sorting Algorithms"
g++ -o sort BubbleSort.cpp -std=c++17
./sort
```

> Most files include a `main()` function with sample test cases ready to run.

---

## 🧩 Code Style & Conventions

All files follow a consistent competitive programming template:

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
```

- **Well-commented** — every non-trivial function includes inline explanations
- **Modular** — classes and functions are self-contained and reusable
- **Problem links** — source problems are cited at the bottom of each file

---

## 📈 Ongoing Development

This repository is actively maintained. Planned additions include:

- [ ] Advanced Graph Algorithms (Bellman-Ford, Floyd-Warshall, MST)
- [ ] Trie & Suffix Arrays
- [ ] Advanced Dynamic Programming (Bitmask DP, Digit DP, SOS DP)
- [ ] Number Theory (Extended GCD, Chinese Remainder Theorem)
- [ ] Queue & Deque implementations
- [ ] Disjoint Set Union (DSU / Union-Find)

---

## 🤝 Contributing

Contributions, suggestions, and feedback are welcome! If you find a bug or want to add a new topic:

1. Fork the repository
2. Create a new branch (`git checkout -b feature/new-topic`)
3. Commit your changes (`git commit -m "Add: new topic"`)
4. Push to the branch (`git push origin feature/new-topic`)
5. Open a Pull Request

---

## 📄 License

This project is open for educational use. Feel free to use, modify, and share for learning purposes.

---

<p align="center">
  <strong><em>"Strong fundamentals build strong engineers."</em></strong>
</p>
