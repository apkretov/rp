public class DeckOfCardsTest { // Fig. 7.11: DeckOfCardsTest.java // Card shuffling and dealing application.
   public static void main(String args[]) { // execute application
      DeckOfCards myDeckOfCards = new DeckOfCards();
      myDeckOfCards.shuffle(); // place Cards in random order
      for (int i = 0; i < 13; i++) { // print all 52 Cards in the order in which they are dealt
         System.out.printf("%-20s%-20s%-20s%-20s\n", myDeckOfCards.dealCard(), myDeckOfCards.dealCard(), myDeckOfCards.dealCard(), myDeckOfCards.dealCard()); // deal and print 4 Cards
      }
   }
}
