// ==== HEADER FILES AND NAMESPACE ====
#include <iostream> // For input/output operations (like cout and cin)
#include <vector>   // To use the vector data structure
using namespace std;    // To avoid writing std:: before cout, cin, etc.

// ==== GLOBAL VARIABLE ====
// A global vector to store the user's input.
// Note: While this works, for larger programs it's often better to declare vectors inside main() or pass them to functions.
vector<int> arr;

int main() {
    // ==== VARIABLE DECLARATION ====
    int ch = 1;     // 'ch' (choice) controls the input loop. The loop continues as long as ch is 1.
    int flag = 0;   // 'flag' is used to enforce the "1s followed by 0s" rule. It becomes 1 after the first 0 is entered.
    int num;        // 'num' will temporarily hold the number entered by the user.

    // ==== INTERACTIVE INPUT LOOP ====
    // This loop prompts the user to enter numbers one by one.
    while (ch == 1) {
        cout << "No: ";
        cin >> num;

        // Case 1: The user enters a 0.
        if (num == 0) {
            flag = 1; // Set the flag to 1, indicating a 0 has been seen.
            arr.push_back(num); // Add the 0 to our array.
        }
        // Case 2: A 0 has already been entered (flag is 1), and the user now tries to enter a 1.
        else if (flag == 1) {
            cout << "The Input is Wrong ,No 1 after 0" << endl; // This input is invalid, so we print an error.
        }
        // Case 3: The user enters a 1, and no 0s have been seen yet (flag is 0).
        else if (num == 1) {
            arr.push_back(num); // This is valid, so add the 1 to our array.
        }
        // Case 4: The user enters something other than 0 or 1.
        else {
            cout << "Only 1's and 0's are allowed" << endl; // Print an error for invalid numbers.
        }

        // Ask the user if they want to continue adding numbers.
        cout << "Want to add one more? (1 for Yes, 0 for No): ";
        cin >> ch;
    }

    // ==== PRINT THE FINAL ARRAY ====
    // This loop prints the content of the array that was just created.
    cout << "\nYour final array is: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ==== BINARY SEARCH SETUP ====
    int low = 0;                    // The starting index for our search.
    int high = arr.size() - 1;      // The ending index for our search.
    int mid = high / 2;             // Initial calculation of the middle index.
    int total = 0;                  // This will store the final count of zeros.

    // ==== BINARY SEARCH LOGIC ====
    // This loop efficiently finds the number of zeros without checking every element.
    while (low <= high) {
        // This condition checks if we are at the "transition point" where the last 1 meets the first 0.
        // NOTE: The `arr[mid+1]` part can cause an error if `mid` points to the last element of the array.
        if (arr[mid] == 1 && (mid + 1 < arr.size()) && arr[mid + 1] == 0) {
            // We found the exact spot! The number of zeros is the total size minus the index of the first zero.
            total = arr.size() - (mid + 1);
            break; // Exit the loop since we found our answer.
        }
        // This condition means we are still in the section of 1s.
        else if (arr[mid] == 1) {
            // The transition point must be to the right, so we discard the left half.
            low = mid + 1;
        }
        // This condition means we are in the section of 0s.
        else {
            // The transition point could be `mid` or somewhere to its left, so we discard the right half.
            high = mid - 1;
        }

        // Recalculate the middle index for the next iteration.
        mid = (low + high) / 2;
    }

    // ==== FINAL OUTPUT ====
    // Print the result calculated from the binary search.
    cout << "Total NO. of 0's: " << total << endl;

    return 0; // Indicate successful execution of the program.
}
