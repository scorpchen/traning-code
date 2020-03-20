package showType;

import java.awt.Font;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;
import javax.swing.JTextField;

public class Shower extends JFrame{
	public static final int WIN_X = 700, WIN_Y = 300;
	public static final int HEIGHT = 250, WIDTH = 500;
	
	public Shower(int x, int y, int h, int w) {
		// set screen
        this.setTitle("forfun");
        this.setLocation(x, y);
        this.setSize(w, h);
        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        this.setResizable(false);
        this.setVisible(true);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Shower window = new Shower(WIN_X, WIN_Y, HEIGHT, WIDTH);
		
		
		JTextField text = new JTextField("No Type");
        text.setBorder(null);
        text.setFont(new Font("Serif", Font.BOLD, 50));
        text.setHorizontalAlignment(JTextField.CENTER);
        text.setEditable(false);
        window.add(text);
        text.setBounds(-10, -20, WIDTH, HEIGHT);
        window.repaint();
        
		window.addKeyListener( new KeyAdapter() {
			boolean flag = false;
			int key;
			String str;
			public void keyPressed(KeyEvent e) {
				key = e.getKeyCode();
				str = e.getKeyText(key);
	            text.setText(str);
	            flag = true;
	        }
			public void keyReleased(KeyEvent e) {
				if(flag == true) {
					text.setText("ÉÏÒ»¸ö£º" + str);
				}
				else {
					text.setText("No Type");
				}
			}
		});
	}

	
}
