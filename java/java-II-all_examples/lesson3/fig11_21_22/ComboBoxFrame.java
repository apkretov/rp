import java.awt.FlowLayout; // Fig. 11.21: ComboBoxFrame.java // Using a JComboBox to select an image to display.
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JComboBox;
import javax.swing.Icon;
import javax.swing.ImageIcon;

public class ComboBoxFrame extends JFrame {
   private JComboBox imagesJComboBox; // combobox to hold names of icons
   private JLabel label; // label to display selected icon

   private String names[] = {"bug1.gif", "bug2.gif",  "travelbug.gif", "buganim.gif"};
   /* ORIG
   private Icon icons[] = { 
      new ImageIcon(getClass().getResource(names[0])),
      new ImageIcon(getClass().getResource(names[1])), 
      new ImageIcon(getClass().getResource(names[2])),
      new ImageIcon(getClass().getResource(names[3])) };
   */

   public ComboBoxFrame() { // ComboBoxFrame constructor adds JComboBox to JFrame
      super("Testing JComboBox");
      setLayout(new FlowLayout()); // set frame layout     
      imagesJComboBox = new JComboBox(names); // set up JComboBox
      imagesJComboBox.setMaximumRowCount(3); // display three rows
      imagesJComboBox.addItemListener(
         new ItemListener() { // anonymous inner class
            public void itemStateChanged(ItemEvent event) { // handle JComboBox event
               if (event.getStateChange() == ItemEvent.SELECTED) // determine whether checkbox selected
                  label/*ORIG .setIcon(icons[imagesJComboBox.getSelectedIndex()])*/.setText(imagesJComboBox.getSelectedItem().toString());
            }
         }
     );

      add(imagesJComboBox); // add combobox to JFrame
      label = new JLabel(/*ORIG icons*/names[0]); // display first icon
      add(label); // add label to JFrame
   }

   /*private void setLabel() { //TEST
      label.setText("Item selected: " + imagesJComboBox.getSelectedItem().toString());
   }*/
}
