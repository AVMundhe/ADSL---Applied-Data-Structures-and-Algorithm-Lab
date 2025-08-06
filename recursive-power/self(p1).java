import java.util.Scanner;

public class Power {

    public static long power(int base, int exp) {
        if (exp == 0) {
            return 1;
        }
        return base * power(base, exp - 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the base number: ");
        int base = sc.nextInt();

        System.out.print("Enter the exponent (non-negative): ");
        int exp = sc.nextInt();

        long result = power(base, exp);

        System.out.println("Result: " + result);

        sc.close();
    }
}
