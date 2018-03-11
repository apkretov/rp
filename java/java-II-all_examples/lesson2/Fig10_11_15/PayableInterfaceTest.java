public class PayableInterfaceTest { // Fig. 10.15: PayableInterfaceTest.java // Tests interface Payable.
   public static void main(String args[]) {
      Payable payableObjects[] = new Payable[4]; // create four-element Payable array
      payableObjects[0] = new Invoice("01234", "seat", 2, 375.00); // populate array with objects that implement Payable
      payableObjects[1] = new Invoice("56789", "tire", 4, 79.95);
      payableObjects[2] = new SalariedEmployee("John", "Smith", "111-11-1111", 800.00);
      payableObjects[3] = new SalariedEmployee("Lisa", "Barnes", "888-88-8888", 1200.00);

      System.out.println("Invoices and Employees processed polymorphically:\n"); 
      for (Payable currentPayable : payableObjects) { // generically process each element in array payableObjects
         System.out.printf("%s \n%s: $%,.2f\n\n", currentPayable.toString(), "payment due", currentPayable.getPaymentAmount()); // output currentPayable and its appropriate payment amount
      }
   }
}