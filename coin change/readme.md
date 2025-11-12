# 🪙 Coin Change Problem (Dynamic Programming)

## 📜 Problem Statement
You are given `n` types of coins with different denominations and a target sum.  
Your task is to find the **total number of distinct ways** to make up that target sum using the available coins.  
Each coin can be used **any number of times**.

---

## 💡 Approach
1. Take input for the number of coins `n` and their denominations.  
2. Take input for the target sum.  
3. Use a **Dynamic Programming (DP)** approach where `dp[i]` represents the number of ways to make sum `i`.  
4. Initialize `dp[0] = 1` since there is one way to make sum `0` (by choosing no coins).  
5. For each coin:
   - For every sum from that coin value up to the target, update `dp[i] += dp[i - coin]`.  
6. Finally, print `dp[sum]` as the total number of ways.

---

## 🧠 Code
```java
import java.util.*;

class CoinChangeDP {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of coins: ");
        int n = sc.nextInt();

        int[] coins = new int[n];
        System.out.println("Enter coin denominations:");
        for (int i = 0; i < n; i++)
            coins[i] = sc.nextInt();

        System.out.print("Enter target sum: ");
        int sum = sc.nextInt();

        // dp[i] will store number of ways to make sum i
        int[] dp = new int[sum + 1];
        dp[0] = 1; // base case

        for (int coin : coins) {
            for (int i = coin; i <= sum; i++) {
                dp[i] += dp[i - coin];
            }
        }

        System.out.println("\nNumber of ways to make sum = " + dp[sum]);
    }
}
🧪 Test Cases
✅ Test Case 1
Input

yaml
Copy code
Enter number of coins: 3
Enter coin denominations:
1 2 3
Enter target sum: 4
Output

bash
Copy code
Number of ways to make sum = 4
✅ Test Case 2
Input

yaml
Copy code
Enter number of coins: 4
Enter coin denominations:
2 5 3 6
Enter target sum: 10
Output

bash
Copy code
Number of ways to make sum = 5
✅ Test Case 3
Input

yaml
Copy code
Enter number of coins: 2
Enter coin denominations:
5 10
Enter target sum: 3
Output

bash
Copy code
Number of ways to make sum = 0
