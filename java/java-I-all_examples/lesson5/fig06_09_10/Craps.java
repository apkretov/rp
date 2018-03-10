import java.util.Random; // Fig. 6.9: Craps.java Craps class simulates the dice game craps.

public class Craps {
   private Random randomNumbers = new Random(); // create random number generator for use in method rollDice
   private enum Status { CONTINUE, WON, LOST }; // enumeration with constants that represent the game status
   private final static int SNAKE_EYES = 2; // constants that represent common rolls of the dice
   private final static int TREY = 3;
   private final static int SEVEN = 7;
   private final static int YO_LEVEN = 11;
   private final static int BOX_CARS = 12;

   public void play() { // plays one game of craps
      int myPoint = 0; // point if no win or loss on first roll
      Status gameStatus; // can contain CONTINUE, WON or LOST
      int sumOfDice = rollDice(); // first roll of the dice
      switch (sumOfDice) { // determine game status and point based on first roll 
         case SEVEN: // win with 7 on first roll
         case YO_LEVEN: // win with 11 on first roll           
            gameStatus = Status.WON;
            break;
         case SNAKE_EYES: // lose with 2 on first roll
         case TREY: // lose with 3 on first roll
         case BOX_CARS: // lose with 12 on first roll
            gameStatus = Status.LOST;
            break;
         default: // did not win or lose, so remember point         
            gameStatus = Status.CONTINUE; // game is not over
            myPoint = sumOfDice; // remember the point
            System.out.printf("Point is %d\n", myPoint);
            break; // optional at end of switch
      }
      while (gameStatus == Status.CONTINUE) { // while game is not complete // not WON or LOST
         sumOfDice = rollDice(); // roll dice again
         if (sumOfDice == myPoint) // determine game status // win by making point
            gameStatus = Status.WON;
         else 
            if (sumOfDice == SEVEN) // lose by rolling 7 before point
               gameStatus = Status.LOST;
      }
      if (gameStatus == Status.WON) // display won or lost message
         System.out.println("Player wins");
      else
         System.out.println("Player loses");
   }

   public int rollDice() { // roll dice, calculate sum and display results
      int die1 = 1 + randomNumbers.nextInt(6); // pick random die values // first die roll
      int die2 = 1 + randomNumbers.nextInt(6); // second die roll
      int sum = die1 + die2; // sum of die values
      System.out.printf("Player rolled %d + %d = %d\n", die1, die2, sum); // display results of this roll
      return sum; // return sum of dice
   }
}
