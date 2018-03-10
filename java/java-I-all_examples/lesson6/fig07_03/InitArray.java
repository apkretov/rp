public class InitArray { // Fig. 7.3: InitArray.java // Initializing the elements of an array with an array initializer.
   public static void main( String args[] ) {
      int array[] = { 32, 27, 64, 18, 95, 14, 90, 70, 60, 37 }; // initializer list specifies the value for each element
      System.out.printf( "%s%8s\n", "Index", "Value" ); // column headings
      for ( int counter = 0; counter < array.length; counter++ ) // output each array element's value 
         System.out.printf( "%5d%8d\n", counter, array[ counter ] );
   }
}
