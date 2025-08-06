# Problem: Count Zeros in a Sorted Binary Array

**Source:** ADSL Coursework / Common Interview Question

---

## Problem Statement

Given a binary array which is sorted in descending order (all 1s appear before all 0s), write an efficient program to count the total number of 0s in it.

---

## Input Format

* An array or vector of integers containing only `1`s and `0`s.
* The array is guaranteed to be sorted, e.g., `[1, 1, 1, 0, 0]`.

## Output Format

* A single integer representing the total count of zeros in the array.

## Constraints

* The array size can be large, so a solution better than linear time ($O(n)$) is preferred.
* $0 \le \text{array size} \le 10^6$

---

## Examples

### Example 1:

**Input:**
[1, 1, 1, 0, 0]


**Output:**

2


### Example 2:

**Input:**

[1, 1, 1, 1, 1, 1]


**Output:**

0


---

## My Approach / Logic

The problem can be solved by finding the index of the **first occurrence of 0**. Since the array is sorted with all 1s followed by all 0s, all elements after the first 0 will also be 0s.

A naive approach would be to iterate through the array with a simple loop ($O(n)$ time complexity). However, because the array is sorted, we can use a much more efficient **Binary Search** algorithm ($O(\log n)$ time complexity).

**Algorithm Steps:**
1.  Initialize `low = 0` and `high = size - 1`.
2.  Use a `while` loop to perform the binary search (`low <= high`).
3.  Calculate the `mid` index. The goal is to find the "transition point".
    * If `arr[mid]` is `1`: The transition point must be to the right. So, we set `low = mid + 1`.
    * If `arr[mid]` is `0`: This could be the first `0`. The transition point is either here or to the left. So, we set `high = mid - 1`.
4.  By the end of the search, the `low` pointer will be at the index of the first `0`.
5.  The total number of zeros is then `array.size() - low`.
