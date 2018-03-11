// Fig. 19.8: Sort1.java
// Using algorithm sort.
import java.util.List;
import java.util.Arrays;
import java.util.Collections;

public class Sort1 
{
   private static final String suits[] = 
      { "Hearts", "Diamonds", "Clubs", "Spades" };

   // display array elements
   public void printElements()
   {
      List< String > list = Arrays.asList( suits ); // create List
      
      // output list
      System.out.printf( "Unsorted array elements:\n%s\n", list );

      Collections.sort( list ); // sort ArrayList

      // output list
      System.out.printf( "Sorted array elements:\n%s\n", list );
   } // end method printElements

   public static void main( String args[] )
   {
      Sort1 sort1 = new Sort1();
      sort1.printElements();
   } // end main
} // end class Sort1

