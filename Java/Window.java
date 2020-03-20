package forfun;

import java.awt.Font;
import java.awt.Frame;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Random;

import javax.swing.JButton;
import javax.swing.JTextField;



public class Window extends Frame{
	public static final int WIN_X = 700, WIN_Y = 300;
	public static final int HEIGHT = 250, WIDTH = 500;
	
	
	public void init(int x, int y, int h, int w) {
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
	


	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		Window window = new Window();
		window.init(WIN_X, WIN_Y, HEIGHT, WIDTH);
		
		JTextField text = new JTextField("你是猪吗？");
		text.setBounds(180, 100, 150, 35);
        text.setBorder(null);
        text.setFont(new Font("Serif", Font.BOLD, 20));
        window.add(text);
        
        JButton btnYes = new JButton("是");
		btnYes.setBounds(90, 170, 70, 35);  
		window.add(btnYes);
		
		JButton btnNo = new JButton("不是");
		window.add(btnNo);
		btnNo.setBounds(340, 170, 70, 35); 
		
        window.repaint();
        

		btnNo.addMouseListener( new MouseListener() {
			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseEntered(MouseEvent e) {
				// TODO Auto-generated method stub
				
				window.init(new Random().nextInt( 1400 ) + 1, new Random().nextInt( 800 ) + 1, HEIGHT, WIDTH);
				btnNo.setBounds(340, 170, 70, 35); 
				window.repaint();
				
			}

			@Override
			public void mouseExited(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
		});
		
		btnYes.addMouseListener( new MouseListener() {
			@Override
			public void mouseClicked(MouseEvent e) {
				// TODO Auto-generated method stub
				text.setBounds(160, 100, 200, 35);
				text.setText("你是猪");
				btnNo.setVisible(false);
				btnYes.setVisible(false);
				window.repaint();
			}

			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseEntered(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}

			@Override
			public void mouseExited(MouseEvent e) {
				// TODO Auto-generated method stub
				
			}
		});
        
	}

}


