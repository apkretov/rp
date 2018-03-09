import java.util.Scanner; // Fig. 3.14: AccountTest.java Inputting and outputting floating-point numbers with Account objects.

public class AccountTest {
   public static void main(String args[]) { // main method begins execution of Java application
      Account account1 = new Account(50.00); // create Account object
      Account account2 = new Account(-7.53); // create Account object

      System.out.printf("account1 balance: $%.2f\n", account1.getBalance()); // display initial balance of each object
      System.out.printf("account2 balance: $%.2f\n\n", account2.getBalance());

      Scanner input = new Scanner(System.in); // create Scanner to obtain input from command window
      double depositAmount; // deposit amount read from user

      System.out.println("Enter deposit amount for account1: "); // prompt
      depositAmount = input.nextDouble(); // obtain user input
      System.out.printf("\nadding %.2f to account1 balance\n\n", depositAmount);
      account1.credit(depositAmount); // add to account1 balance

      System.out.printf("account1 balance: $%.2f\n", account1.getBalance()); // display balances
      System.out.printf("account2 balance: $%.2f\n\n", account2.getBalance());

      System.out.print("Enter deposit amount for account2: "); // prompt
      depositAmount = input.nextDouble(); // obtain user input
      System.out.printf("\nadding %.2f to account2 balance\n\n", depositAmount);
      account2.credit(depositAmount); // add to account2 balance

      System.out.printf("account1 balance: $%.2f\n", account1.getBalance()); // display balances
      System.out.printf("account2 balance: $%.2f\n", account2.getBalance());
   }
}
