cmake_minimum_required(VERSION 3.20)
project(cpp-data-structures)

set(CMAKE_CXX_STANDARD 20)

# ── Linked Lists ──────────────────────────────
add_executable(SLL          SLL.cpp)
add_executable(DLL          DLL.cpp)

# ── Stack & Queue ─────────────────────────────
add_executable(Stack        Stack.cpp)
add_executable(Queue        Queue.cpp)

# ── Trees ─────────────────────────────────────
add_executable(Trees        Trees.cpp)

# ── Sorting ───────────────────────────────────
add_executable(BasicSort    BasicSort.cpp)
add_executable(MergeSort    MergeSort.cpp)
add_executable(QuickSort    QuickSort.cpp)
add_executable(ShellSort    ShellSort.cpp)

# ── Searching ─────────────────────────────────
add_executable(Searching    Searching.cpp)
add_executable(BinarySearch BinarySearch.cpp)

# ── Graph, Hash, Heap ─────────────────────────
add_executable(Graph        Graph.cpp)
add_executable(Hash         Hash.cpp)
add_executable(Heap         Heap.cpp)

# ── Recursion ─────────────────────────────────
add_executable(recursion    recursion.cpp )