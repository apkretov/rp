import java.util.EnumSet; // Fig. 8.11: EnumTest.java // Testing enum type Book.

public class EnumTest {
   public static void main(String args[]) {
      System.out.println("All books:\n");
      for (Book book : Book.values()) // print all books in enum Book
         System.out.printf("%-10s%-45s%s\n", book, book.getTitle(), book.getCopyrightYear());

      System.out.println("\nDisplay a range of enum constants:\n");
      for (Book book : EnumSet.range(Book.JHTP6, Book.CPPHTP4)) // print first four books                                 
         System.out.printf("%-10s%-45s%s\n", book, book.getTitle(), book.getCopyrightYear());
   }
}
