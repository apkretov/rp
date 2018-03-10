public class ThisTest { // Fig. 8.4: ThisTest.java // this used implicitly and explicitly to refer to members of an object.
   public static void main(String args[]) {
      SimpleTime time = new SimpleTime(15, 30, 19);
      System.out.println(time.buildString());
   }
}

class SimpleTime { // class SimpleTime demonstrates the "this" reference
   private int hour;   // 0-23
   private int minute; // 0-59
   private int second; // 0-59 

   public SimpleTime(int hour, int minute, int second) { // if the constructor uses parameter names identical to instance variable names the "this" reference is required to distinguish between names
      this.hour = hour;      // set "this" object's hour
      this.minute = minute;  // set "this" object's minute
      this.second = second;  // set "this" object's second
   }

   public String buildString() { // use explicit and implicit "this" to call toUniversalString
      return String.format("%24s: %s\n%24s: %s", "this.toUniversalString()", this.toUniversalString(), "toUniversalString()", toUniversalString());
   }

   public String toUniversalString() { // convert to String in universal-time format (HH:MM:SS)
      return String.format("%02d:%02d:%02d", this.hour, this.minute, this.second); // "this" is not required here to access instance variables, because method does not have local variables with same names as instance variables
   }
}