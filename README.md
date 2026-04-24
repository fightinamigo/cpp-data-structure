# 🧠 C++ Data Structures & Algorithms Library

A comprehensive implementation of core data structures and algorithms built **from scratch in C++**, without relying on STL containers. Each structure is implemented with full operations, edge case handling, and clean code comments.

---

## 📚 What's Implemented

### 🔗 Linked Lists
#### Singly Linked List (`SLL.cpp`)
| Method | Description |
|---|---|
| `append` / `prepend` | Add to end / beginning |
| `deleteFirst` / `deleteLast` / `deleteNode` | Remove nodes |
| `get` / `set` / `insert` | Access and modify by index |
| `reverse` | Reverse the entire list |
| `findMiddleNode` | Floyd's two-pointer technique |
| `hasLoop` | Floyd's cycle detection algorithm |
| `findKthFromEnd` | Two-pointer kth node finder |
| `removeDuplicates` | Remove all duplicate values |
| `binaryToDecimal` | Convert binary LL to decimal |
| `partitionList` | Partition around value x |
| `reverseBetween` | Reverse sublist from m to n |
| `swapPairs` | Swap every two adjacent nodes |

#### Doubly Linked List (`DLL.cpp`)
All SLL operations plus:
| Method | Description |
|---|---|
| Bidirectional `get` | O(n/2) — searches from nearest end |
| `palindromeChecker` | Uses head + tail pointers |
| `partitionList` | DLL-aware with prev pointer handling |
| `reverseBetween` | Full DLL reverse with dummy node |
| `swapPairs` | DLL-aware pair swapping |

---

### 📦 Stack & Queue (`Stack.cpp`, `Queue.cpp`)
| Structure | Operations |
|---|---|
| Stack (linked list) | `push`, `pop` (returns value), `printStack` |
| Queue (linked list) | `enqueue`, `dequeue`, `getFirst`, `getLast` |

**Bonus algorithms using Stack:**
- `reverseString` — reverse any string using a stack
- `isBalancedParentheses` — validate bracket matching
- `sortStack` — sort a stack using a second auxiliary stack

---

### 🌳 Trees (`Trees.cpp`)

**Binary Search Tree (BST)**

| Method | Description |
| --- | --- |
| `insert` | Iterative insertion, equal values go left |
| `contains` | Iterative search, O(log n) average |
| `inOrder` | Left → Root → Right, outputs sorted ascending order |
| `preOrder` | Root → Left → Right, useful for copying the tree |
| `postOrder` | Left → Right → Root, useful for deleting the tree |
| `deleteNode` | Recursive deletion — handles leaf, one child, and two children (in-order successor) cases |
| `search` | Finds all nodes with an exact value, handles duplicates |
| `displayLessOrEqual` | Prints all nodes with value <= limit in sorted order |
| `displayGreaterOrEqual` | Prints all nodes with value >= limit in sorted order |
---

### 📊 Sorting Algorithms

| Algorithm | File | Time Complexity |
|---|---|---|
| Bubble Sort | `BasicSort.cpp` | O(n²) |
| Selection Sort | `BasicSort.cpp` | O(n²) |
| Insertion Sort | `BasicSort.cpp` | O(n²) best O(n) |
| Merge Sort | `MergeSort.cpp` | O(n log n) |
| Quick Sort | `QuickSort.cpp` | O(n log n) avg |
| Shell Sort | `ShellSort.cpp` | O(n log n) avg |

> QuickSort includes **two implementations**: classic pivot-based and two-pointer approach.

---

### 🔍 Searching Algorithms (`Searching.cpp`, `BinarySearch.cpp`)
| Algorithm | Complexity |
|---|---|
| Linear Search | O(n) |
| Binary Search (iterative) | O(log n) |
| Binary Search (recursive) | O(log n) |

---

### 🕸️ Graph (`Graph.cpp`)
Undirected graph using **adjacency list** (`unordered_map` + `unordered_set`)

| Method | Description |
|---|---|
| `addVertex` | Add a new vertex |
| `addEdge` | Connect two vertices (bidirectional) |
| `removeEdge` | Disconnect two vertices |
| `removeVertex` | Remove vertex and all its edges |
| `printGraph` | Display full adjacency list |

---

### #️⃣ Hash Table (`Hash.cpp`)
Custom hash table with **separate chaining** (linked list per bucket)

| Method | Description |
|---|---|
| `hash` | Custom hash function using ASCII values |
| `set` | Insert key-value pair |
| `get` | Retrieve value by key |
| `keys` | Return all keys as a vector |
| `printTable` | Display full hash table |

---

## 🛠️ Build & Run

**Requirements:** C++20, CMake 4.0+

```bash
git clone https://github.com/YOUR_USERNAME/cpp-data-structures
cd cpp-data-structures

# Example: build linked lists
cd LL-DataStructure
mkdir build && cd build
cmake ..
make
./SLL
./DLL
```

---

## 📁 Project Structure

```
├── LL-DataStructure/
│   ├── SLL.cpp
│   ├── DLL.cpp
│   └── CMakeLists.txt
├── Stack&Queue-DataStructure/
│   ├── Stack.cpp
│   ├── Queue.cpp
│   └── CMakeLists.txt
├── Trees-DataStructure/
│   ├── Trees.cpp
│   └── CMakeLists.txt
├── SORT-DataStructure/
│   ├── BasicSort.cpp
│   ├── MergeSort.cpp
│   ├── QuickSort.cpp
│   ├── ShellSort.cpp
│   ├── Searching.cpp
│   ├── BinarySearch.cpp
│   └── CMakeLists.txt
└── HGH-DataStructure/
    ├── Graph.cpp
    ├── Hash.cpp
    ├── Heap.cpp
    └── CMakeLists.txt
```

---

## 📌 Notes

- All structures are implemented **from scratch** — no STL containers used for the core logic
- Commented-out code blocks show alternative implementations and thought process
- Each file is self-contained and independently runnable
