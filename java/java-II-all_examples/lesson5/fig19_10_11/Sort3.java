// Fig. 19.11: Sort3.java
// Sort a list using the custom Comparator class TimeComparator.
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class Sort3 
{
   public void printElements()
   {
      List< Time2 > list = new ArrayList< Time2 >(); // create List

      list.add( new Time2(  6, 24, 34 ) );
      list.add( new Time2( 18, 14, 58 ) );
      list.add( new Time2(  6, 05, 34 ) );
      list.add( new Time2( 12, 14, 58 ) );
      list.add( new Time2(  6, 24, 22 ) );
      
      // output List elements
      System.out.printf( "Unsorted array elements:\n%s\n", list );

      // sort in order using a comparator
      Collections.sort( list, new TimeComparator() ); 

      // output List elements
      System.out.printf( "Sorted list elements:\n%s\n", list );
   } // end method printElements
 
   public static void main( String args[] )
   {
      Sort3 sort3 = new Sort3();
      sort3.printElements();
   } // end main
} // end class Sort3

