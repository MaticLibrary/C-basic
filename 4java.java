import java.util.Scanner;

public class PrimeNumberChecker {
    public static void CheckPrimary() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter Number: ");
        int primeNumber = scanner.nextInt();
        System.out.println("You entered: " + primeNumber);
        if (primeNumber > 0 && primeNumber % primeNumber == 0 && primeNumber % 1 == 0 && primeNumber % 2 != 0 && primeNumber % 3 != 0 || primeNumber == 2 || primeNumber == 3 || primeNumber == 4 || primeNumber == 5) {
            System.out.println("Prime Number: " + primeNumber);
        }else{
            System.out.println("Thats not a Prime Number: " + primeNumber);
        }
        scanner.close();
    }
    public static void main(String[] args) {
        CheckPrimary();
    }
}
