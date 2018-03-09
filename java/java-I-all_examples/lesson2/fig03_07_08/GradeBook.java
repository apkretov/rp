
public class GradeBook { // Fig. 3.7: GradeBook.java GradeBook class that contains a courseName instance variable and methods to set and get its value.
   private String courseName; // course name for this GradeBook
   
   public void setCourseName(String name) { // method to set the course name
      courseName = name; // store the course name
   }
   
   public String getCourseName() { // method to retrieve the course name
      return courseName;
   }
   
   public void displayMessage() { // display a welcome message to the GradeBook user
      System.out.printf("Welcome to the grade book for\n%s!\n", getCourseName()); // this statement calls getCourseName to get the name of the course this GradeBook represents
   } 
} 
