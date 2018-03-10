public class InitArray { // Fig. 7.21: InitArray.java // Using command-line arguments to initialize an array.
   public static void main(String[] args) {
      if (args.length != 3) // check number of command-line arguments
         System.out.println("Error: Please re-enter the entire command, including\n" + "an array size, initial value and increment.");
      else {
         int arrayLength = Integer.parseInt(args[0]); // get array size from first command-line argument
         int array[] = new int[arrayLength]; // create array

         int initialValue = Integer.parseInt(args[1]); // get initial value and increment from command-line arguments
         int increment = Integer.parseInt(args[2]);
         
         for (int counter = 0; counter < array.length; counter++) // calculate value for each array element
            array[counter] = initialValue + increment * counter;

         System.out.printf("%s%8s\n", "Index", "Value");         
         for (int counter = 0; counter < array.length; counter++) // display array index and value
            System.out.printf("%5d%8d\n", counter, array[counter]);
      }
   }
}
