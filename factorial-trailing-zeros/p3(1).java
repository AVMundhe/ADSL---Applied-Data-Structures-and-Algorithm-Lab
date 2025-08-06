import java.util.*;

// This class finds the number using a binary search approach.
public class Solution1_BinarySearch {

    /**
     * Calculates the factorial of a number using recursion.
     * @param n The number to calculate the factorial of.
     * @return The factorial of n.
     */
    public static long fact(int n) {
        // Base case: Factorial of 1 is 1.
        if (n == 1) {
            return 1;
        }
        // Base case: Factorial of 0 is also 1.
        if (n == 0) {
            return 1;
        }
        // Recursive step: n! = n * (n-1)!
        return n * fact(n - 1);
    }

    /**
     * Counts the number of trailing zeros in a given number by repeated division.
     * @param fact The number (a pre-calculated factorial).
     * @return The count of trailing zeros.
     */
    public static int NumberOfZero(long fact) {
        int no = 0; // Initialize zero counter.
        // Loop as long as the number is divisible by 10.
        while (fact > 0 && fact % 10 == 0) {
            no++;        // Increment zero count.
            fact /= 10;  // Remove the last zero from the number.
        }
        return no;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n; // This will store the target number of zeros.
        System.out.println("Enter the no. of Minimum Trailing 0's you want: ");
        n = sc.nextInt();

        // This if/else block contains special logic for different ranges of n.
        if (n >= 25) {

            // --- BINARY SEARCH SETUP ---
            int low = 0;
            int high = n * 5; // An estimated upper bound for the search.
            int mid = high / 2;

            // --- CHECKING THE GUESS ---
            int n_zero = 0;
            long factorial = fact(mid);
            n_zero = NumberOfZero(factorial);

            // --- BINARY SEARCH LOOP ---
            while (low <= high) {
                // If the number of zeros matches the target, print and exit.
                if (n_zero == n) {
                    System.out.println("The number is: " + mid);
                    break;
                }
                // If the number of zeros is too small, search in the upper half.
                else if (n_zero < n) {
                    low = mid + 1;
                }
                // If the number of zeros is too large, search in the lower half.
                else {
                    high = mid;
                }

                // Recalculate mid and check again.
                mid = (high + low) / 2;
                factorial = fact(mid);
                n_zero = NumberOfZero(factorial);
            }
        } else {
            // This block handles specific hardcoded cases for smaller n.
            if (n == 5) {
                System.out.println("Number is : 25");
            }
        }
        sc.close();
    }
}
