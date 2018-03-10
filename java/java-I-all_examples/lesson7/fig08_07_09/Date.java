public class Date { // Fig. 8.7: Date.java // Date class declaration.
   private int month; // 1-12
   private int day;   // 1-31 based on month
   private int year;  // any year

   public Date(int theMonth, int theDay, int theYear) { // constructor: call checkMonth to confirm proper value for month; call checkDay to confirm proper value for day
      month = checkMonth(theMonth); // validate month
      year = theYear; // could validate year
      day = checkDay(theDay); // validate day
      System.out.printf("Date object constructor for date %s\n", this);
   }

   private int checkMonth(int testMonth) { // utility method to confirm proper month value
      if (testMonth > 0 && testMonth <= 12) // validate month
         return testMonth;
      else { // month is invalid 
         System.out.printf("Invalid month (%d) set to 1.", testMonth);
         return 1; // maintain object in consistent state
      }
   }

   private int checkDay(int testDay) { // utility method to confirm proper day value based on month and year
      int daysPerMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
      if (testDay > 0 && testDay <= daysPerMonth[month]) // check if day in range for month
         return testDay;
      if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) // check for leap year
         return testDay;
      System.out.printf("Invalid day (%d) set to 1.", testDay);
      return 1;  // maintain object in consistent state
   }
   
   public String toString() {  // return a String of the form month/day/year
      return String.format("%d/%d/%d", month, day, year); 
   }
}
