public class GradeBook { // Fig. 3.10: GradeBook.java GradeBook class with a constructor to initialize the course name.
   private String courseName; // course name for this GradeBook
   
   public GradeBook(String name) { // constructor initializes courseName with String supplied as argument
      courseName = name; // initializes courseName
   }
   
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
