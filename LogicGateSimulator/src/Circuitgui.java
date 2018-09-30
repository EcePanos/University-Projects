import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JTextArea;




public class Circuitgui extends JFrame {
	public static JTextArea breadboard;
	public Circuitgui(){
		super("BreadBoard");
		setLayout(new FlowLayout());
		breadboard=new JTextArea();
		breadboard.setEditable(false);
		for (int i=0;i<Board.rows;i++){
			for(int j=0;j<Board.columns;j++){
				breadboard.setText(breadboard.getText()+Board.board[j][i].get()+"\t");
				
			}
			breadboard.setText(breadboard.getText()+"\n");
		}
		
		add(breadboard);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.pack();
		this.setVisible(true);
	}
	public static void refresh(){
		breadboard.setText("");
		for (int i=0;i<Board.rows;i++){
			for(int j=0;j<Board.columns;j++){
				breadboard.setText(breadboard.getText()+Board.board[j][i].get()+"\t");
				
			}
			breadboard.setText(breadboard.getText()+"\n");
		}
	}
	 
		
	}

