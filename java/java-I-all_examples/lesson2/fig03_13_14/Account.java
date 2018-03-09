public class Account { // Fig. 3.13: Account.java Account class with a constructor to initialize instance variable balance.
   private double balance; // instance variable that stores the balance

   public Account(double initialBalance) { // constructor  
      if (initialBalance > 0.0) // validate that initialBalance is greater than 0.0; if it is not, balance is initialized to the default value 0.0
         balance = initialBalance; 
   }
   
   public void credit(double amount) { // credit (add) an amount to the account
      balance = balance + amount; // add amount to balance 
   }
   
   public double getBalance() { // return the account balance
      return balance; // gives the value of balance to the calling method
   }
}