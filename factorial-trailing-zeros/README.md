# Problem: Smallest Number with N Trailing Zeros in Factorial

---

## Problem Statement

Given an integer `n`, find the smallest non-negative integer `x` such that its factorial, `x!`, ends with at least `n` zeros.

---

## Input Format

* A single integer `n`, representing the desired number of trailing zeros.

## Output Format

* A single integer `x`, the smallest number that satisfies the condition.

---

## Examples

### Example 1:

**Input:**

1


**Output:**

5


### Example 2:

**Input:**

6


**Output:**

25

---

## Approach #1: Binary Search with Full Factorial Calculation

This solution uses a binary search algorithm to find the required number `x`.

* **Framework:** The code searches for `x` within a range, continually narrowing it down.
* **Check Function:** For each number (`mid`) that the binary search tests, the code performs two steps:
    1.  It calculates the complete factorial of `mid` using a recursive `fact()` method.
    2.  It then counts the trailing zeros of the resulting factorial number by repeatedly dividing it by 10 until it's no longer divisible.
* **Logic:** The binary search adjusts its range (`low` or `high`) based on whether the number of zeros found is less than, equal to, or greater than the target `n`.

## Approach #2: Direct Heuristic Formula

This solution uses a direct mathematical formula to calculate the number `x`.

* **Framework:** Instead of searching, this approach attempts to compute the result directly.
* **Logic:** The formula is based on a multi-step heuristic:
    1.  It begins with an initial approximation by multiplying the target number of zeros `n` by 5.
    2.  It then calculates a correction value (`dif`) based on multiples of 25.
    3.  Finally, it subtracts a value derived from this correction factor to arrive at the fi
