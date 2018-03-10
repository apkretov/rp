import java.util.Random; // Fig. 7.10: DeckOfCards.java // DeckOfCards class represents a deck of playing cards.

public class DeckOfCards {
   private Card deck[]; // array of Card objects
   private int currentCard; // index of next Card to be dealt
   private final int NUMBER_OF_CARDS = 52; // constant number of Cards
   private Random randomNumbers; // random number generator

   public DeckOfCards() { // constructor fills deck of Cards
      String faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
      String suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
      deck = new Card[NUMBER_OF_CARDS]; // create array of Card objects
      currentCard = 0; // set currentCard so first Card dealt is deck[0]
      randomNumbers = new Random(); // create random number generator
      for (int count = 0; count < deck.length; count++) // populate deck with Card objects
         deck[count] = new Card(faces[count % 13], suits[count / 13]);
   }
   
   public void shuffle() { // shuffle deck of Cards with one-pass algorithm
      currentCard = 0; // after shuffling, dealing should start at deck[0] again // reinitialize currentCard
      for (int first = 0; first < deck.length; first++) { // for each Card, pick another random Card and swap them
         int second =  randomNumbers.nextInt(NUMBER_OF_CARDS); // select a random number between 0 and 51 
         Card temp = deck[first]; // swap current Card with randomly selected Card
         deck[first] = deck[second];   
         deck[second] = temp;            
      }
   }
   
   public Card dealCard() { // deal one Card
      if (currentCard < deck.length) // determine whether Cards remain to be dealt
         return deck[currentCard++]; // return current Card in array
      else        
         return null; // return null to indicate that all Cards were dealt
   }
}