// Fig. 3.8: GradeBookTest.java Create and manipulate a GradeBook object.
import java.util.Scanner; // program uses Scanner

public class GradeBookTest {
   public static void main(String args[]) { // main method begins program execution
      Scanner input = new Scanner(System.in); // creaet Scanner to obtain input from command window
      GradeBook myGradeBook = new GradeBook(); // create a GradeBook object and assign it to myGradeBook
      System.out.printf("Initial course name is: %s\n\n", myGradeBook.getCourseName()); // display initial value of courseName
      
      System.out.println("Please enter the course name:"); // prompt for and read course name
      String theName = input.nextLine(); // read a line of text
      myGradeBook.setCourseName(theName); // set the course name
      System.out.println(); // outputs a blank line
      
      myGradeBook.displayMessage(); // display welcome message after specifying course name
   }
}
