public class PassArray { // Fig. 7.13: PassArray.java // Passing arrays and individual array elements to methods.
   public static void main(String args[]) { // main creates array and calls modifyArray and modifyElement
      int array[] = {1, 2, 3, 4, 5};

      System.out.println("Effects of passing reference to entire array:\n" + "The values of the original array are:");
      for (int value : array) // output original array elements 
         System.out.printf("   %d", value);
      modifyArray(array); // pass array reference
      System.out.println("\n\nThe values of the modified array are:");
      for (int value : array) // output modified array elements 
         System.out.printf("   %d", value);
   
      System.out.printf("\n\nEffects of passing array element value:\n" + "array[3] before modifyElement: %d\n", array[3]);
      modifyElement(array[3]); // attempt to modify array[3]
      System.out.printf("array[3] after modifyElement: %d\n", array[3]);
   }
   
   public static void modifyArray(int array2[]) { // multiply each element of an array by 2 
      for (int counter = 0; counter < array2.length; counter++)
         array2[counter] *= 2;
   }
   
   public static void modifyElement(int element) { // multiply argument by 2
      element *= 2;
      System.out.printf(
         "Value of element in modifyElement: %d\n", element);
   }
}
