// ==== HEADER FILES AND NAMESPACE ====
#include <iostream>
#include <vector>
using namespace std;

// ==== GLOBAL VARIABLES ====
// Note: Using global variables can make code harder to debug. It's often better
// to pass variables as function parameters.
vector<int> v;  // This global vector is declared but not used in the final code.
int count = 0;    // This global count is declared but not used.
int n;            // Stores the size of the array, used in main.
int last;         // Used as a pointer within the 'merge' function.

/**
 * @brief This function partitions a sub-array to move its zeros to the right end.
 * @param arr The array being modified.
 * @param low The starting index of the sub-array.
 * @param high The ending index of the sub-array.
 *
 * NOTE: The function is named 'merge' but it performs a partitioning/segregation operation, not a standard merge.
 */
void merge(int arr[], int low, int high) {
    last = high; // Initialize the 'last' pointer to the end of the current sub-array.

    // Iterate through the sub-array from left to right with pointer 'i'.
    for (int i = low; i <= high; i++) {
        // If we find a zero at the current position 'i'...
        if (arr[i] == 0) {
            int flag = 0; // A flag to ensure we only perform one swap for the zero at 'i'.

            // Start a search from the 'last' end of the sub-array to find a non-zero to swap with.
            while (flag != 1 && i < last) {
                // This check is redundant because the outer while loop condition `i < last` already handles it.
                if (i >= last) {
                    flag = 1;
                }
                
                // Check if the element at the 'last' pointer is NOT zero.
                if (arr[last] != 0) {
                    // If it's a non-zero, swap it with the zero at 'i'.
                    int temp = arr[last];
                    arr[last] = arr[i];
                    arr[i] = temp;

                    last--;   // Move the 'last' pointer inwards as this position is now settled.
                    flag = 1; // Set flag to 1 to exit the inner while loop.
                } else {
                    // If the element at 'last' is also a zero, just move the pointer inwards
                    // to find the next non-zero element.
                    last--;
                }
            }
        }
    }
}

/**
 * @brief Recursively divides the array into two halves.
 * @param arr The array being modified.
 * @param low The starting index of the division.
 * @param high The ending index of the division.
 * This function follows the classic Divide and Conquer structure.
 */
void divide(int arr[], int low, int high) {
    // Base case for the recursion: if the sub-array has 0 or 1 elements, stop.
    if (low >= high) {
        return;
    }

    int mid = (low + high) / 2;

    // Recursively call 'divide' on the left half.
    divide(arr, low, mid);
    // Recursively call 'divide' on the right half.
    divide(arr, mid + 1, high);
    // After the two halves are processed, call 'merge' to partition the combined sub-array.
    merge(arr, low, high);
}

int main() {
    // ==== USER INPUT ====
    cout << "Enter the Size of Array: ";
    cin >> n;

    // Declare a Variable Length Array (VLA). Note: VLA is not standard C++.
    // Using std::vector is generally safer and more standard.
    int arr[n];
    last = n - 1; // Initialize global 'last', though it's reset in 'merge'.

    for (int i = 0; i < n; i++) {
        cout << "Enter at " << i << " index: ";
        cin >> arr[i];
    }

    // ==== PRINT ORIGINAL ARRAY ====
    cout << "\nOrignal : " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ==== START THE ALGORITHM ====
    // Initial call to the divide function to start the process on the whole array.
    divide(arr, 0, n - 1);

    // ==== PRINT FINAL ARRAY ====
    cout << endl << "Final Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
