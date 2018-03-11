public abstract class Employee { // Fig. 10.4: Employee.java // Employee abstract superclass.
   private String firstName;
   private String lastName;
   private String socialSecurityNumber;
   
   public Employee(String first, String last, String ssn) { // three-argument constructor
      firstName = first;
      lastName = last;
      socialSecurityNumber = ssn;
   }

   public void setFirstName(String first) { // set first name
      firstName = first;
   }

   public String getFirstName() { // return first name
      return firstName;
   }

   public void setLastName(String last) { // set last name
      lastName = last;
   }

   public String getLastName() { // return last name
      return lastName;
   }

   public void setSocialSecurityNumber(String ssn) { // set social security number
      socialSecurityNumber = ssn; // should validate
   } 

   public String getSocialSecurityNumber() { // return social security number
      return socialSecurityNumber;
   }

   public String toString() { // return String representation of Employee object
      return String.format("%s %s\nsocial security number: %s", getFirstName(), getLastName(), getSocialSecurityNumber());
   }

   public abstract double earnings(); // abstract method overridden by subclasses // no implementation here
}
