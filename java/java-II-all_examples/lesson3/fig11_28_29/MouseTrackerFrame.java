import java.awt.Color; // Fig. 11.28: MouseTrackerFrame.java // Demonstrating mouse events.
import java.awt.BorderLayout;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseEvent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class MouseTrackerFrame extends JFrame {
   private JPanel mousePanel; // panel in which mouse events will occur
   private JLabel statusBar; // label that displays event information

   public MouseTrackerFrame() { // MouseTrackerFrame constructor sets up GUI and registers mouse event handlers
      super("Demonstrating Mouse Events");

      mousePanel = new JPanel(); // create panel
      mousePanel.setBackground(Color.WHITE); // set background color
      add(mousePanel, BorderLayout.CENTER); // add panel to JFrame

      statusBar = new JLabel("Mouse outside JPanel"); 
      add(statusBar, BorderLayout.SOUTH); // add label to JFrame

      MouseHandler handler = new MouseHandler(); // create and register listener for mouse and mouse motion events
      mousePanel.addMouseListener(handler); 
      mousePanel.addMouseMotionListener(handler); 
   }

   private class MouseHandler implements MouseListener, MouseMotionListener {
      public void mouseClicked(MouseEvent event) { // MouseListener event handlers handle event when mouse released immediately after press
         statusBar.setText(String.format("Clicked at [%d, %d]", event.getX(), event.getY()));
      }

      public void mousePressed(MouseEvent event) { // handle event when mouse pressed
         statusBar.setText(String.format("Pressed at [%d, %d]", event.getX(), event.getY()));
      }
      
      public void mouseReleased(MouseEvent event) { // handle event when mouse released after dragging
         statusBar.setText(String.format("Released at [%d, %d]", event.getX(), event.getY()));
      }

      public void mouseEntered(MouseEvent event) { // handle event when mouse enters area
         statusBar.setText(String.format("Mouse entered at [%d, %d]", event.getX(), event.getY()));
         mousePanel.setBackground(Color.GREEN);
      }

      public void mouseExited(MouseEvent event) { // handle event when mouse exits area
         statusBar.setText("Mouse outside JPanel");
         mousePanel.setBackground(Color.WHITE);
      }

      public void mouseDragged(MouseEvent event) { // MouseMotionListener event handlers handle event when user drags mouse with button pressed
         statusBar.setText(String.format("Dragged at [%d, %d]", event.getX(), event.getY()));
      }

      public void mouseMoved(MouseEvent event) { // handle event when user moves mouse
         statusBar.setText(String.format("Moved at [%d, %d]", event.getX(), event.getY()));
      }
   }
}
