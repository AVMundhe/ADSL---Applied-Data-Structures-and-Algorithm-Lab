# Problem: Segregate Zeros to the End of an Array

**Source:** ADSL Coursework

---

## Problem Statement

Given an array of random integers, rearrange it such that all the zero elements are moved to the end of the array. The relative order of the non-zero elements does not need to be preserved.

---

## Input Format

* The first line contains an integer `n`, the size of the array.
* The next `n` lines (or a single line of space-separated integers) contain the elements of the array.

## Output Format

* The modified array with all zeros moved to the end.

---

## Examples

### Example 1:

**Input:**

[1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0]


**Output:**

[1, 9, 8, 4, 6, 7, 2, 0, 0, 0, 0]

*(Note: The order of non-zero elements like 6, 7, 2 might differ based on the swap logic, but all zeros are at the end.)*

---

## My Approach / Logic

The implemented solution uses a **Divide and Conquer** strategy, which is structurally similar to a Merge Sort algorithm.

1.  **`divide` function:** This function recursively splits the array into smaller sub-arrays until each sub-array contains only one element (the base case `low >= high`).

2.  **`merge` function:** This is the core of the logic. Despite its name, it doesn't merge two sorted halves. Instead, it **partitions** the given sub-array (`low` to `high`).
    * It uses a two-pointer-like approach within the sub-array. A pointer `i` iterates from the `low` end, and another pointer `last` starts from the `high` end.
    * When `i` finds a zero (`arr[i] == 0`), it looks for a non-zero element at the `last` position.
    * If `arr[last]` is not zero, it swaps `arr[i]` and `arr[last]`, effectively moving the zero towards the end and the non-zero towards the start of the sub-array.
    * If `arr[last]` is also a zero, it simply decrements `last` to find the next available non-zero element to swap with.
    * This process is applied bottom-up on all sub-arrays as the recursion unwinds, eventually segregating the zeros in the entire array.

While this approach works, a more standard and efficient ($O(n)$) solution for this prohis problem is a single pass with two pointers over the entire array. However, this implementation is an interesting application of the divide-and-conquer paradigm.
