public class GradeBookTest { // Fig. 3.11: GradeBookTest.java GradeBook constructor used to specify the course name at the time each GradeBook object is created.
   public static void main(String args[]) { // main method begins program execution
      GradeBook gradeBook1 = new GradeBook("CS101 Introduction to Java Programming"); // create GradeBook object
      GradeBook gradeBook2 = new GradeBook("CS102 Data Structures in Java");
      System.out.printf("gradeBook1 course name is: %s\n", gradeBook1.getCourseName()); // display initial value of courseName for each GradeBook
      System.out.printf("gradeBook2 course name is: %s\n", gradeBook2.getCourseName());
   }
}
