# Problem: Calculate Power of a Number Using Recursion

**Source:** ADSL Coursework

---

## Problem Statement

Write a program that takes two integers as input, a `base` and an `exponent`, and calculates the result of `base` raised to the power of `exponent` using a recursive function.

---

## Input Format

* An integer for the `base`.
* A non-negative integer for the `exponent`.

## Output Format

* The result of `base` ^ `exponent`.

---

## Example

**Input:**

Enter the base number: 3
Enter the exponent (non-negative): 4


**Output:**

Result: 81


---

## Approach: Simple Recursion

The solution uses a straightforward recursive function to compute the power.

* **Base Case:** The recursion terminates when the exponent (`exp`) becomes 0. In this case, the function returns 1, because any number raised to the power of 0 is 1.
* **Recursive Step:** For any exponent greater than 0, the function follows the mathematical definition 
