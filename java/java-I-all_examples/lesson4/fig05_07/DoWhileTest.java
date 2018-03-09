// Fig. 5.7: DoWhileTest.java
// do...while repetition statement.

public class DoWhileTest 
{  
   public static void main( String args[] )
   {
      int counter = 1; // initialize counter

      do 
      {
         System.out.printf( "%d  ", counter );
         ++counter;
      } while ( counter <= 10 ); // end do...while 

      System.out.println(); // outputs a newline
   } // end main
} // end class DoWhileTest
