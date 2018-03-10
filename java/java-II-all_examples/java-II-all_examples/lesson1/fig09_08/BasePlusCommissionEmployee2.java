public class BasePlusCommissionEmployee2 extends CommissionEmployee { // Fig. 9.8: BasePlusCommissionEmployee2.java // BasePlusCommissionEmployee2 inherits from class CommissionEmployee.
   private double baseSalary; // base salary per week

   public BasePlusCommissionEmployee2(String first, String last, String ssn, double sales, double rate, double salary) { // six-argument constructor
      super(first, last, ssn, sales, rate); // explicit call to superclass CommissionEmployee constructor
      setBaseSalary(salary); // validate and store base salary
   }
   
   public void setBaseSalary(double salary) { // set base salary
      baseSalary = (salary < 0.0) ? 0.0 : salary;
   }

   public double getBaseSalary() { // return base salary
      return baseSalary;
   }

   public double earnings() { // calculate earnings
      return baseSalary + (commissionRate * grossSales); // not allowed: commissionRate and grossSales private in superclass
   }

   public String toString() { // return String representation of BasePlusCommissionEmployee2
      return String.format( // not allowed: attempts to access private superclass members   
         "%s: %s %s\n%s: %s\n%s: %.2f\n%s: %.2f\n%s: %.2f", 
         "base-salaried commission employee", firstName, lastName, 
         "social security number", socialSecurityNumber, 
         "gross sales", grossSales, "commission rate", commissionRate, 
         "base salary", baseSalary);
   }
}
