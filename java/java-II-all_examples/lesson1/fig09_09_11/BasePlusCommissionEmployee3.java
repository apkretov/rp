public class BasePlusCommissionEmployee3 extends CommissionEmployee2 { // Fig. 9.10: BasePlusCommissionEmployee3.java // BasePlusCommissionEmployee3 inherits from CommissionEmployee2 and has access to CommissionEmployee2's protected members.
   private double baseSalary; // base salary per week

   public BasePlusCommissionEmployee3(String first, String last, String ssn, double sales, double rate, double salary) { // six-argument constructor
      super(first, last, ssn, sales, rate);
      setBaseSalary(salary); // validate and store base salary
   }
   
   public void setBaseSalary(double salary) { // set base salary
      baseSalary = (salary < 0.0) ? 0.0 : salary;
   }

   public double getBaseSalary() { // return base salary
      return baseSalary;
   }

   public double earnings() { // calculate earnings
      return baseSalary + (commissionRate * grossSales);
   }

   public String toString() { // return String representation of BasePlusCommissionEmployee3
      return String.format(
         "%s: %s %s\n%s: %s\n%s: %.2f\n%s: %.2f\n%s: %.2f", 
         "base-salaried commission employee", firstName, lastName, 
         "social security number", socialSecurityNumber, 
         "gross sales", grossSales, "commission rate", commissionRate,
         "base salary", baseSalary);
   } 
} 