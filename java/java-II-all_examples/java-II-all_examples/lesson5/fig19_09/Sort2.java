// Fig. 19.9: Sort2.java
// Using a Comparator object with algorithm sort.
import java.util.List;
import java.util.Arrays;
import java.util.Collections;

public class Sort2 
{
   private static final String suits[] = 
      { "Hearts", "Diamonds", "Clubs", "Spades" };

   // output List elements
   public void printElements()
   {
      List< String > list = Arrays.asList( suits ); // create List

      // output List elements
      System.out.printf( "Unsorted array elements:\n%s\n", list );

      // sort in descending order using a comparator
      Collections.sort( list, Collections.reverseOrder() ); 

      // output List elements
      System.out.printf( "Sorted list elements:\n%s\n", list );
   } // end method printElements
 
   public static void main( String args[] )
   {
      Sort2 sort2 = new Sort2();
      sort2.printElements();
   } // end main
} // end class Sort2

