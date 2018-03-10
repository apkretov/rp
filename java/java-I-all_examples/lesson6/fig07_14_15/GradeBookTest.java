public class GradeBookTest { // Fig. 7.15: GradeBookTest.java // Creates GradeBook object using an array of grades.
   public static void main(String args[]) { // main method begins program execution
      int gradesArray[] = {87, 68, 94, 100, 83, 78, 85, 91, 76, 87}; // one-dimensional array of student grades
      GradeBook myGradeBook = new GradeBook("CS101 Introduction to Java Programming", gradesArray);
      myGradeBook.displayMessage();
      myGradeBook.processGrades();
   }
}
