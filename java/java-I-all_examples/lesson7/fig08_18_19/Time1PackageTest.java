import com.deitel.jhtp7.ch08.Time1; // Fig. 8.18: Time1PackageTest.java // Time1 object used in an application. // import class Time1

public class Time1PackageTest {
   public static void main(String args[]) {
      Time1 time = new Time1(); // create and initialize a Time1 object // calls Time1 constructor
      //TEST com.deitel.jhtp7.ch08.Time1 time = new com.deitel.jhtp7.ch08.Time1(); // create and initialize a Time1 object // calls Time1 constructor

      System.out.print("The initial universal time is: "); // output string representations of the time
      System.out.println(time.toUniversalString());
      System.out.print("The initial standard time is: ");
      System.out.println(time.toString());
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
      System.out.println(time.toString());
   }
}