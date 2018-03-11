// Fig. 19.5: UsingToArray.java
// Using method toArray.
import java.util.LinkedList;
import java.util.Arrays;

public class UsingToArray 
{
   // constructor creates LinkedList, adds elements and converts to array
   public UsingToArray()
   {
      String colors[] = { "black", "blue", "yellow" };

      LinkedList< String > links = 
         new LinkedList< String >( Arrays.asList( colors ) );

      links.addLast( "red" );   // add as last item
      links.add( "pink" );      // add to the end
      links.add( 3, "green" );  // add at 3rd index
      links.addFirst( "cyan" ); // add as first item      

      // get LinkedList elements as an array     
      colors = links.toArray( new String[ links.size() ] );

      System.out.println( "colors: " );

      for ( String color : colors )
         System.out.println( color );
   } // end UsingToArray constructor

   public static void main( String args[] )
   {
      new UsingToArray();
   } // end main 
} // end class UsingToArray

