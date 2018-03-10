public class GradeBook { // Fig. 7.14: GradeBook.java // Grade book using an array to store test grades.
   private String courseName; // name of course this GradeBook represents
   private int grades[]; // array of student grades
   
   public GradeBook(String name, int gradesArray[]) { // two-argument constructor initializes courseName and grades array
      courseName = name; // initialize courseName
      grades = gradesArray; // store grades
   }
   
   public void setCourseName(String name) { // method to set the course name
      courseName = name; // store the course name
   }
   
   public String getCourseName() { // method to retrieve the course name
      return courseName;
   }
   
   public void displayMessage() { // display a welcome message to the GradeBook user
      System.out.printf("Welcome to the grade book for\n%s!\n\n", getCourseName()); // getCourseName gets the name of the course
   }
   
   public void processGrades() { // perform various operations on the data
      outputGrades(); // output grades array
      System.out.printf("\nClass average is %.2f\n", getAverage()); // call method getAverage to calculate the average grade      
      System.out.printf("Lowest grade is %d\nHighest grade is %d\n\n", getMinimum(), getMaximum()); // call methods getMinimum and getMaximum
      outputBarChart(); // call outputBarChart to print grade distribution chart
   }
   
   public int getMinimum() { // find minimum grade
      int lowGrade = grades[ 0 ]; // assume grades[ 0 ] is smallest
      for (int grade : grades) { // loop through grades array
         if (grade < lowGrade) // if grade lower than lowGrade, assign it to lowGrade
            lowGrade = grade; // new lowest grade
      }
      return lowGrade; // return lowest grade
   }
   
   public int getMaximum() { // find maximum grade
      int highGrade = grades[ 0 ]; // assume grades[ 0 ] is largest
      for (int grade : grades) { // loop through grades array
         if (grade > highGrade) // if grade greater than highGrade, assign it to highGrade
            highGrade = grade; // new highest grade
      }
      return highGrade; // return highest grade
   }
   
   public double getAverage() { // determine average grade for test
      int total = 0; // initialize total
      for (int grade : grades) // sum grades for one student
         total += grade;
      return (double) total / grades.length; // return average of grades
   }
   
   public void outputBarChart() { // output bar chart displaying grade distribution
      System.out.println("Grade distribution:");
      int frequency[] = new int[ 11 ]; // stores frequency of grades in each range of 10 grades
      for (int grade : grades) // for each grade, increment the appropriate frequency 
         ++frequency[ grade / 10 ];
      for (int count = 0; count < frequency.length; count++) { // for each grade frequency, print bar in chart
         if (count == 10) // output bar label ("00-09: ", ..., "90-99: ", "100: ")
            System.out.printf("%5d: ", 100); 
         else
            System.out.printf("%02d-%02d: ", count * 10, count * 10 + 9);
         for (int stars = 0; stars < frequency[ count ]; stars++) // print bar of asterisks
            System.out.print("*");
         System.out.println(); // start a new line of output
      }
   }

   public void outputGrades() { // output the contents of the grades array
      System.out.println("The grades are:\n");
      for (int student = 0; student < grades.length; student++) // output each student's grade
         System.out.printf("Student %2d: %3d\n", student + 1, grades[ student ]);
   }
}