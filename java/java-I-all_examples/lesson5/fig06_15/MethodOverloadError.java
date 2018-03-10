// Fig. 6.15: MethodOverload.java // Overloaded methods with identical signatures cause compilation errors, even if return types are different.

public class MethodOverloadError { 
   public int square( int x ) { // declaration of method square with int argument
      return x * x;
   }  
   
   public double square( int y ) { // second declaration of method square with int argument causes compilation error even though return types are different
      return y * y;
   }
}