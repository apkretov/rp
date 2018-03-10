public enum Book { // Fig. 8.10: Book.java // Declare an enum type with constructor and explicit instance fields and accessors for these fields
   JHTP6("Java How to Program 6e", "2005"), // declare constants of enum type
   CHTP4("C How to Program 4e", "2004"),                           
   IW3HTP3("Internet & World Wide Web How to Program 3e", "2004"),
   CPPHTP4("C++ How to Program 4e", "2003"),                       
   VBHTP2("Visual Basic .NET How to Program 2e", "2002"),
   CSHARPHTP("C# How to Program", "2002");

   private final String title; // instance fields  // book title 
   private final String copyrightYear; // copyright year

   Book(String bookTitle, String year) { // enum constructor
      title = bookTitle;
      copyrightYear = year;
   }
   
   public String getTitle() { // accessor for field title
      return title;
   }
   
   public String getCopyrightYear() { // accessor for field copyrightYear
      return copyrightYear;
   }
}
