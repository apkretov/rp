public class Card { // Fig. 7.9: Card.java // Card class represents a playing card.
   private String face; // face of card ("Ace", "Deuce", ...)
   private String suit; // suit of card ("Hearts", "Diamonds", ...)

   public Card( String cardFace, String cardSuit ) { // two-argument constructor initializes card's face and suit
      face = cardFace; // initialize face of card
      suit = cardSuit; // initialize suit of card
   }
   
   public String toString() { // return String representation of Card
      return face + " of " + suit;
   }
}
