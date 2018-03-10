public class Time1Test { // Fig. 8.2: Time1Test.java // Time1 object used in an application.
   public static void main(String args[]) {
      Time1 time = new Time1(); // create and initialize a Time1 object // invokes Time1 constructor

      System.out.print("The initial universal time is: "); // output string representations of the time
      System.out.println(time.toUniversalString());
      System.out.print("The initial standard time is: ");
      System.out.println(time/*ORIG .toString()*/);
      System.out.println(); // output a blank line

      time.setTime(13, 27, 6); // change time and output updated time 
      System.out.print("Universal time after setTime is: ");
      System.out.println(time.toUniversalString());
      System.out.print("Standard time after setTime is: ");
      System.out.println(time.toString());
      System.out.println(); // output a blank line

      time.setTime(99, 99, 99); // set time with invalid values; output updated time 
      System.out.println("After attempting invalid settings:");
      System.out.print("Universal time: ");
      System.out.println(time.toUniversalString());
      System.out.print("Standard time: ");
      System.out.println(time/*ORIG .toString()*/);
   }
}
