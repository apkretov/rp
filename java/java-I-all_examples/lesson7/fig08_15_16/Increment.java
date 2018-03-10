public class Increment { // Fig. 8.15: Increment.java // final instance variable in a class.
   private int total = 0; // total of all increments
   private final int INCREMENT; // constant variable (uninitialized)

   public Increment(int incrementValue) { // constructor initializes final instance variable INCREMENT
      INCREMENT = incrementValue; // initialize constant variable (once)
   }

   public void addIncrementToTotal() { // add INCREMENT to total
      total += INCREMENT;
   }

   public String toString() { // return String representation of an Increment object's data
      return String.format("total = %d", total);
   }
}
