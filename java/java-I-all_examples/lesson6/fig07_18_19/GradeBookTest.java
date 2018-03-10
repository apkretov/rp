public class GradeBookTest { // Fig. 7.19: GradeBookTest.java // Creates GradeBook object using a two-dimensional array of grades.
   public static void main( String args[] ) { // main method begins program execution
      int gradesArray[][] = { { 87, 96, 70 }, // two-dimensional array of student grades
                              { 68, 87, 90 },
                              { 94, 100, 90 },
                              { 100, 81, 82 },
                              { 83, 65, 85 },
                              { 78, 87, 65 },
                              { 85, 75, 83 }, 
                              { 91, 94, 100 },
                              { 76, 72, 84 },
                              { 87, 93, 73 } };
      GradeBook myGradeBook = new GradeBook("CS101 Introduction to Java Programming", gradesArray);
      myGradeBook.displayMessage();
      myGradeBook.processGrades();
   }
}