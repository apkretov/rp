public class IncrementTest { // Fig. 8.16: IncrementTest.java // final variable initialized with a constructor argument.
   public static void main(String args[]) {
      Increment value = new Increment(5);
      System.out.printf("Before incrementing: %s\n\n", value);
      for (int i = 1; i <= 3; i++) {
         value.addIncrementToTotal();
         System.out.printf("After increment %d: %s\n", i, value);
      }
   }
}