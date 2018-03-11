import java.awt.FlowLayout; // Fig. 11.15: ButtonFrame.java // Creating JButtons.
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;

public class ButtonFrame extends JFrame {
   private JButton plainJButton; // button with just text
   private JButton fancyJButton; // button with icons

   public ButtonFrame() { // ButtonFrame adds JButtons to JFrame
      super("Testing Buttons");
      setLayout(new FlowLayout()); // set frame layout

      plainJButton = new JButton("Plain Button"); // button with text
      add(plainJButton); // add plainJButton to JFrame

      //ORIG Icon bug1 = new ImageIcon(getClass().getResource("bug1.gif"));
      //ORIG Icon bug2 = new ImageIcon(getClass().getResource("bug2.gif"));
      fancyJButton = new JButton("Fancy Button"/*ORIG , bug1*/); // set image
      //ORIG fancyJButton.setRolloverIcon(bug2); // set rollover image
      add(fancyJButton); // add fancyJButton to JFrame

      ButtonHandler handler = new ButtonHandler(); // create new ButtonHandler for button event handling 
      fancyJButton.addActionListener(handler);
      plainJButton.addActionListener(handler);
   } 

   private class ButtonHandler implements ActionListener { // inner class for button event handling
      public void actionPerformed(ActionEvent event) { // handle button event
         JOptionPane.showMessageDialog(ButtonFrame.this, String.format("You pressed: %s", event.getActionCommand()));
      }
   }
}
