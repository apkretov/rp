// Fig. 19.19: SortedSetTest.java
// Using TreeSet and SortedSet.
import java.util.Arrays;
import java.util.SortedSet;
import java.util.TreeSet;

public class SortedSetTest 
{
   private static final String names[] = { "yellow", "green",
       "black", "tan", "grey", "white", "orange", "red", "green" };
   
   // create a sorted set with TreeSet, then manipulate it
   public SortedSetTest()
   {
      // create TreeSet
      SortedSet< String > tree = 
         new TreeSet< String >( Arrays.asList( names ) );

      System.out.println( "sorted set: " );
      printSet( tree ); // output contents of tree

      // get headSet based on "orange"
      System.out.print( "\nheadSet (\"orange\"):  " );
      printSet( tree.headSet( "orange" ) );

      // get tailSet based upon "orange"
      System.out.print( "tailSet (\"orange\"):  " );
      printSet( tree.tailSet( "orange" ) );

      // get first and last elements
      System.out.printf( "first: %s\n", tree.first() );
      System.out.printf( "last : %s\n", tree.last() );
   } // end SortedSetTest constructor

   // output set
   private void printSet( SortedSet< String > set )
   {
      for ( String s : set )
         System.out.print( s + " " );

      System.out.println();
   } // end method printSet

   public static void main( String args[] )
   {
      new SortedSetTest();
   } // end main
} // end class SortedSetTest

