public class InitArray { // Fig. 7.2: InitArray.java // Creating an array.
   public static void main(String args[]) {
      int array[]; // declare array named array
      array = new int[10]; // create the space for array
      System.out.printf("%s%8s\n", "Index", "Value"); // column headings   
      for (int counter = 0; counter < array.length; counter++) // output each array element's value 
         System.out.printf("%5d%8d\n", counter, array[counter]);
   }
}
