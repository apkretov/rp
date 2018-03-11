public class PayrollSystemTest { // Fig. 10.9: PayrollSystemTest.java // Employee hierarchy test program.
   public static void main(String args[]) {
      SalariedEmployee salariedEmployee = new SalariedEmployee("John", "Smith", "111-11-1111", 800.00); // create subclass objects
      HourlyEmployee hourlyEmployee = new HourlyEmployee("Karen", "Price", "222-22-2222", 16.75, 40);
      CommissionEmployee commissionEmployee = new CommissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06);
      BasePlusCommissionEmployee basePlusCommissionEmployee = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300);

      System.out.println("Employees processed individually:\n");
      System.out.printf("%s\n%s: $%,.2f\n\n", salariedEmployee, "earned", salariedEmployee.earnings());
      System.out.printf("%s\n%s: $%,.2f\n\n", hourlyEmployee, "earned", hourlyEmployee.earnings());
      System.out.printf("%s\n%s: $%,.2f\n\n", commissionEmployee, "earned", commissionEmployee.earnings());
      System.out.printf("%s\n%s: $%,.2f\n\n", basePlusCommissionEmployee, "earned", basePlusCommissionEmployee.earnings());

      Employee employees[] = new Employee[4]; // create four-element Employee array
      employees[0] = salariedEmployee; // initialize array with Employees
      employees[1] = hourlyEmployee;
      employees[2] = commissionEmployee; 
      employees[3] = basePlusCommissionEmployee;

      System.out.println("Employees processed polymorphically:\n");
      for (Employee currentEmployee : employees) { // generically process each element in array employees
         System.out.println(currentEmployee); // invokes toString
         if (currentEmployee instanceof BasePlusCommissionEmployee) { // determine whether element is a BasePlusCommissionEmployee
            BasePlusCommissionEmployee employee = (BasePlusCommissionEmployee)currentEmployee; // downcast Employee reference to BasePlusCommissionEmployee reference
            double oldBaseSalary = employee.getBaseSalary();
            employee.setBaseSalary(1.10 * oldBaseSalary);
            System.out.printf("new base salary with 10%% increase is: $%,.2f\n", employee.getBaseSalary());
         }
         System.out.printf("earned $%,.2f\n\n", currentEmployee.earnings());
      }

      for (int j = 0; j < employees.length; j++) // get type name of each object in employees array
         System.out.printf("Employee %d is a %s\n", j, employees[j].getClass().getName()); 
   }
}