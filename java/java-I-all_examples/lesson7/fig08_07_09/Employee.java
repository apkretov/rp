public class Employee { // Fig. 8.8: Employee.java // Employee class with references to other objects.
   private String firstName;
   private String lastName;
   private Date birthDate;
   private Date hireDate;

   public Employee(String first, String last, Date dateOfBirth, Date dateOfHire) { // constructor to initialize name, birth date and hire date
      firstName = first;
      lastName = last;
      birthDate = dateOfBirth;
      hireDate = dateOfHire;
   }

   public String toString() { // convert Employee to String format
      return String.format("%s, %s  Hired: %s  Birthday: %s", lastName, firstName, hireDate, birthDate);
   }
}
