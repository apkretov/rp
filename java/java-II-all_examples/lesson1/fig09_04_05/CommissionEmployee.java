public class CommissionEmployee extends Object { // Fig. 9.4: CommissionEmployee.java // CommissionEmployee class represents a commission employee.
   private String firstName;
   private String lastName;
   private String socialSecurityNumber;
   private double grossSales; // gross weekly sales
   private double commissionRate; // commission percentage

   public CommissionEmployee(String first, String last, String ssn, double sales, double rate) { // five-argument constructor
      firstName = first; // implicit call to Object constructor occurs here
      lastName = last;
      socialSecurityNumber = ssn;
      setGrossSales(sales); // validate and store gross sales
      setCommissionRate(rate); // validate and store commission rate
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

   public void setGrossSales(double sales) { // set commission employee's gross sales amount
      grossSales = (sales < 0.0) ? 0.0 : sales;
   }

   public double getGrossSales() { // return commission employee's gross sales amount
      return grossSales;
   }

   public void setCommissionRate(double rate) { // set commission employee's rate
      commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0.0;
   }

   public double getCommissionRate() { // return commission employee's rate
      return commissionRate;
   }

   public double earnings() { // calculate commission employee's pay
      return commissionRate * grossSales;
   }

   public String toString() { // return String representation of CommissionEmployee object
      return String.format("%s: %s %s\n%s: %s\n%s: %.2f\n%s: %.2f", 
         "commission employee", firstName, lastName, 
         "social security number", socialSecurityNumber, 
         "gross sales", grossSales, 
         "commission rate", commissionRate);
   }
}