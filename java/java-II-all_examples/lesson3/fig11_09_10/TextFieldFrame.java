import java.awt.FlowLayout; // Fig. 11.9: TextFieldFrame.java // Demonstrating the JTextField class.
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JPasswordField;
import javax.swing.JOptionPane;

public class TextFieldFrame extends JFrame {
   private JTextField textField1; // text field with set size
   private JTextField textField2; // text field constructed with text
   private JTextField textField3; // text field with text and size
   private JPasswordField passwordField; // password field with text

   public TextFieldFrame() { // TextFieldFrame constructor adds JTextFields to JFrame
      super("Testing JTextField and JPasswordField");
      setLayout(new FlowLayout()); // set frame layout

      textField1 = new JTextField(10); // construct textfield with 10 columns
      add(textField1); // add textField1 to JFrame

      textField2 = new JTextField("Enter text here"); // construct textfield with default text
      add(textField2); // add textField2 to JFrame

      textField3 = new JTextField("Uneditable text field", 21); // construct textfield with default text and 21 columns
      textField3.setEditable(false); // disable editing
      add(textField3); // add textField3 to JFrame

      passwordField = new JPasswordField("Hidden text"); // construct passwordfield with default text
      add(passwordField); // add passwordField to JFrame

      TextFieldHandler handler = new TextFieldHandler(); // register event handlers
      textField1.addActionListener(handler);
      textField2.addActionListener(handler);
      textField3.addActionListener(handler);
      passwordField.addActionListener(handler);
   }

   private class TextFieldHandler implements ActionListener { // private inner class for event handling
      public void actionPerformed(ActionEvent event) { // process textfield events
         String string = ""; // declare string to display
         if (event.getSource() == textField1)
            string = String.format("textField1: %s", event.getActionCommand()); // user pressed Enter in JTextField textField1
         else if (event.getSource() == textField2) // user pressed Enter in JTextField textField2
            string = String.format("textField2: %s", event.getActionCommand());
         else if (event.getSource() == textField3) // user pressed Enter in JTextField textField3
            string = String.format("textField3: %s", event.getActionCommand());
         else if (event.getSource() == passwordField) // user pressed Enter in JTextField passwordField
            string = String.format("passwordField: %s", new String(passwordField.getPassword()));
         JOptionPane.showMessageDialog(null, string); // display JTextField content
      }
   }
}