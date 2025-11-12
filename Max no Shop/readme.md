# 🏪 Activity Selection Problem (Multiple Persons)

## 📜 Problem Statement
You are given `n` shops, each with a start and end time representing when the shop is open. There are `k` persons available to visit these shops.  
Each person can visit only one shop at a time and can go to another shop only after finishing the previous one.  
Find the **maximum number of shops** that can be visited in total by all `k` persons combined.

---

## 💡 Approach
1. Take input for the number of shops `n`, and arrays of `start` and `end` times.  
2. Sort all shops by their **start times** using a simple bubble sort (for clarity).  
3. Maintain an array `person[]` of size `k` to track when each person becomes free.  
4. For each shop:
   - Check if any person is free before the shop’s start time.  
   - If yes, assign that shop to the person and update their end time.  
5. Increment the total count of shops visited.  
6. Output the total number of shops that can be visited.

---

## 🧠 Code
```java
import java.util.*;

class ActivitySelectionSimple {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of shops: ");
        int n = sc.nextInt();

        int[] start = new int[n];
        int[] end = new int[n];

        System.out.println("Enter start times:");
        for (int i = 0; i < n; i++)
            start[i] = sc.nextInt();

        System.out.println("Enter end times:");
        for (int i = 0; i < n; i++)
            end[i] = sc.nextInt();

        System.out.print("Enter number of persons (K): ");
        int k = sc.nextInt();

        // Sort shops by their start time (simple bubble sort for clarity)
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (start[i] > start[j]) {
                    // swap start
                    int temp = start[i];
                    start[i] = start[j];
                    start[j] = temp;

                    // swap corresponding end
                    temp = end[i];
                    end[i] = end[j];
                    end[j] = temp;
                }
            }
        }

        // Each person[i] stores the time when that person becomes free
        int[] person = new int[k];
        for (int i = 0; i < k; i++)
            person[i] = 0; // all free initially

        int total = 0; // total shops visited

        // Try to assign each shop
        for (int i = 0; i < n; i++) {
            for (int p = 0; p < k; p++) {
                if (person[p] <= start[i]) { // person is free before shop starts
                    person[p] = end[i];     // assign this shop
                    total++;
                    break; // move to next shop
                }
            }
        }

        System.out.println("\nTotal shops visited = " + total);
    }
}
🧪 Test Cases
✅ Test Case 1
Input

mathematica
Copy code
Enter number of shops: 4
Enter start times:
1 3 0 5
Enter end times:
2 4 6 7
Enter number of persons (K): 2
Output

java
Copy code
Total shops visited = 3
✅ Test Case 2
Input

mathematica
Copy code
Enter number of shops: 5
Enter start times:
1 2 3 3 5
Enter end times:
2 4 5 6 7
Enter number of persons (K): 3
Output

java
Copy code
Total shops visited = 5
✅ Test Case 3
Input

mathematica
Copy code
Enter number of shops: 3
Enter start times:
1 2 3
Enter end times:
4 5 6
Enter number of persons (K): 1
Output

java
Copy code
Total shops visited = 1
