// Fig. 3.5: GradeBookTest.java // Create GradeBook object and pass a String to its displayMessage method.
import java.util.Scanner; // program uses Scanner

public class GradeBookTest {
   public static void main(String args[]) { // main method begins program execution
      Scanner input = new Scanner(System.in); // create Scanner to obtain input from command window
      GradeBook myGradeBook = new GradeBook(); // create a GradeBook object and assign it to myGradeBook
      
      System.out.println("Please enter the course name:"); // prompt for and input course name
      String courseName = input.nextLine(); // read a line of text
      System.out.println(); // outputs a blank line

      myGradeBook.displayMessage(courseName); // call myGradeBook's displayMessage method and pass courseName as an argument
   }
} 
