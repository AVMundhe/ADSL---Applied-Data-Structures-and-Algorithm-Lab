# Problem: Find Minimum in Rotated Sorted Array
---

## Problem Statement

Suppose an array of numbers sorted in ascending order is rotated at some unknown pivot. For example, the array `[0, 1, 2, 4, 5, 6, 7]` might become `[4, 5, 6, 7, 0, 1, 2]`.

Given such an array, write an efficient algorithm to find the minimum element in it.

---

## Input Format

* An array of integers that was originally sorted and then rotated.

## Output Format

* The minimum integer value found in the array.

---

## Example

**Input:**
[3, 4, 5, 0, 1, 2]


**Output:**
min:0
---

## Approach: Modified Binary Search

The solution uses a modified binary search to find the minimum element in $O(\log n)$ time complexity, which is much more efficient than a linear scan.

The core idea is to determine which half of the current search space contains the pivot (the minimum element).

* **Initialization:** Pointers `low` and `high` are set to the start and end of the array.
* **Comparison Logic:** In each step, the middle element `arr[mid]` is compared with the element at the `high` index.
    * If `arr[mid] > arr[high]`: This indicates that the segment from `low` to `mid` is sorted and "high" (i.e., it contains larger numbers). The pivot point and the minimum value must therefore lie in the right half of the search space. So, we discard the left half by setting `low = mid + 1`.
    * If `arr[mid] <= arr[high]`: This indicates that the segment from `mid` to `high` is sorted. The minimum element could be `arr[mid]` itself or it could be somewhere in the left half. So, we discard the right half by setting `high = mid`.
* **Termination:** The loop continues until `low` and `high` converge (`low == high`). At this point, the `low` pointer will be at the index of the minimum element in the array.
Scroll to the bottom, type a commit
