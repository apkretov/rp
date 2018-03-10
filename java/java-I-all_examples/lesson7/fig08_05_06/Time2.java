public class Time2 { // Fig. 8.5: Time2.java // Time2 class declaration with overloaded constructors.  
   private int hour;   // 0 - 23
   private int minute; // 0 - 59
   private int second; // 0 - 59

   public Time2() { // Time2 no-argument constructor: initializes each instance variable to zero; ensures that Time2 objects start in a consistent state
      this(0, 0, 0); // invoke Time2 constructor with three arguments
   }

   public Time2(int h) { // Time2 constructor: hour supplied, minute and second defaulted to 0
      this(h, 0, 0); // invoke Time2 constructor with three arguments
   }

   public Time2(int h, int m) { // Time2 constructor: hour and minute supplied, second defaulted to 0
      this(h, m, 0); // invoke Time2 constructor with three arguments
   }

   public Time2(int h, int m, int s) { // Time2 constructor: hour, minute and second supplied
      setTime(h, m, s); // invoke setTime to validate time
   }

   public Time2(Time2 time){ // Time2 constructor: another Time2 object supplied
      this(time.getHour(), time.getMinute(), time.getSecond()); // invoke Time2 three-argument constructor
   }

   // Set Methods
   // set a new time value using universal time; ensure that 
   // the data remains consistent by setting invalid values to zero
   public void setTime(int h, int m, int s)
   {
      setHour(h);   // set the hour
      setMinute(m); // set the minute
      setSecond(s); // set the second
   } // end method setTime

   // validate and set hour 
   public void setHour(int h) 
   { 
      hour = ((h >= 0 && h < 24) ? h : 0); 
   } // end method setHour

   // validate and set minute 
   public void setMinute(int m) 
   { 
      minute = ((m >= 0 && m < 60) ? m : 0); 
   } // end method setMinute

   // validate and set second 
   public void setSecond(int s) 
   { 
      second = ((s >= 0 && s < 60) ? s : 0); 
   } // end method setSecond

   // Get Methods
   // get hour value
   public int getHour() 
   { 
      return hour; 
   } // end method getHour

   // get minute value
   public int getMinute() 
   { 
      return minute; 
   } // end method getMinute

   // get second value
   public int getSecond() 
   { 
      return second; 
   } // end method getSecond

   // convert to String in universal-time format (HH:MM:SS)
   public String toUniversalString()
   {
      return String.format(
         "%02d:%02d:%02d", getHour(), getMinute(), getSecond());
   } // end method toUniversalString

   // convert to String in standard-time format (H:MM:SS AM or PM)
   public String toString()
   {
      return String.format("%d:%02d:%02d %s", 
         ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12),
         getMinute(), getSecond(), (getHour() < 12 ? "AM" : "PM"));
   } // end method toString
} // end class Time2
