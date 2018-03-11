// Fig. 10.13: Employee.java
// Employee abstract superclass implements Payable.

public abstract class Employee implements Payable
{
   private String firstName;
   private String lastName;
   private String socialSecurityNumber;

   // three-argument constructor
   public Employee( String first, String last, String ssn )
   {
      firstName = first;
      lastName = last;
      socialSecurityNumber = ssn;
   } 

   // set first name
   public void setFirstName( String first )
   {
      firstName = first;
   } 

   // return first name
   public String getFirstName()
   {
      return firstName;
   } 

   // set last name
   public void setLastName( String last )
   {
      lastName = last;
   } 

   // return last name
   public String getLastName()
   {
      return lastName;
   } 

   // set social security number
   public void setSocialSecurityNumber( String ssn )
   {
      socialSecurityNumber = ssn; // should validate
   } 

   // return social security number
   public String getSocialSecurityNumber()
   {
      return socialSecurityNumber;
   } 

   public String toString() { // return String representation of Employee object
      return String.format( "%s %s\nsocial security number: %s", getFirstName(), getLastName(), getSocialSecurityNumber() );
   }

   // Note: We do not implement Payable method getPaymentAmount here so this class must be declared abstract to avoid a compilation error.
} 
