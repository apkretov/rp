public class Invoice implements Payable { // Fig. 10.12: Invoice.java // Invoice class implements Payable.
   private String partNumber; 
   private String partDescription;
   private int quantity;
   private double pricePerItem;

   public Invoice(String part, String description, int count, double price) { // four-argument constructor
      partNumber = part;
      partDescription = description;
      setQuantity(count); // validate and store quantity
      setPricePerItem(price); // validate and store price per item
   }

   public void setPartNumber(String part) { // set part number
      partNumber = part;  
   } 

   public String getPartNumber() { // get part number
      return partNumber;
   } 

   public void setPartDescription(String description) { // set description
      partDescription = description;
   } 

   public String getPartDescription() { // get description
      return partDescription;
   } 

   public void setQuantity(int count) { // set quantity
      quantity = (count < 0) ? 0 : count; // quantity cannot be negative
   } 

   public int getQuantity() { // get quantity
      return quantity;
   } 

   public void setPricePerItem(double price) { // set price per item
      pricePerItem = (price < 0.0) ? 0.0 : price; // validate price
   } 

   public double getPricePerItem() { // get price per item
      return pricePerItem;
   } 

   public String toString() { // return String representation of Invoice object
      return String.format("%s: \n%s: %s (%s) \n%s: %d \n%s: $%,.2f", 
         "invoice", "part number", getPartNumber(), getPartDescription(), 
         "quantity", getQuantity(), "price per item", getPricePerItem());
   } 

   public double getPaymentAmount() { // method required to carry out contract with interface Payable
      return getQuantity() * getPricePerItem(); // calculate total cost
   }
}
