public class EnhancedForTest { // Fig. 7.12: EnhancedForTest.java // Using enhanced for statement to total integers in an array.
   public static void main(String args[]) {
      int array[] = {87, 68, 94, 100, 83, 78, 85, 91, 76, 87};
      int total = 0;
      for (int number : array) // add each element's value to total
         total += number;
      System.out.printf("Total of array elements: %d\n", total);
   }
}
