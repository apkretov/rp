public class Employee { // Fig. 8.12: Employee.java // Static variable used to maintain a count of the number of Employee objects in memory.
   private String firstName;
   private String lastName;
   private static int count = 0; // number of objects in memory

   public Employee(String first, String last) { // initialize employee, add 1 to static count and output String indicating that constructor was called
      firstName = first;
      lastName = last;

      count++;  // increment static count of employees
      System.out.printf("Employee constructor: %s %s; count = %d\n", firstName, lastName, count);
   }

   protected void finalize() { // subtract 1 from static count when garbage collector calls finalize to clean up object; confirm that finalize was called
      count--; // decrement static count of employees
      System.out.printf("Employee finalizer: %s %s; count = %d\n", firstName, lastName, count);
   }

   public String getFirstName() { // get first name
      return firstName; 
   }

   public String getLastName() { // get last name
      return lastName; 
   }

   public static int getCount() { // static method to get static count value
      return count; 
   }
}
