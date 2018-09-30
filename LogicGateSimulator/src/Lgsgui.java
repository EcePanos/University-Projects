
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class Lgsgui extends JFrame {
 private JComboBox box;
 private JButton finish,nextGate,save,load,newcircuit;
 public static JTextField input1,input2,column,output,tinput1,tinput2,tcolumn,toutput,error;
 static JTextArea pinput1;
static JTextArea pinput2;
static JTextArea pcolumn;
static JTextArea poutput;
static JTextArea pgate;
 private static String[] gates={"And","Or","Not","Nor","Nand","Xor","Xnor"};
 private Gate[] gate={new And(),new Or(),new Not(),new Nor(),new Nand(),new Xor(), new Xnor()};
 public static int counter=0;
 public Lgsgui(){
  super("Logic Gate Simulator");
 
  setLayout(new GridBagLayout());
  
  GridBagConstraints c = new GridBagConstraints();
  //if (shouldFill) {
  //                //natural height, maximum width
  //                c.fill = GridBagConstraints.HORIZONTAL;
  //}
  tinput1 = new JTextField("input1");
  c.weightx = 0.2;
  c.fill = GridBagConstraints.HORIZONTAL;
  tinput1.setEditable(false);
  c.gridx = 0;
  c.gridy = 0;
  add(tinput1, c);
  tinput2 = new JTextField("input2");
  c.weightx = 0.2;
  c.fill = GridBagConstraints.HORIZONTAL;
  tinput2.setEditable(false);
  c.gridx = 1;
  c.gridy = 0;
  add(tinput2, c);
  tcolumn = new JTextField("column");
  c.weightx = 0.2;
  c.fill = GridBagConstraints.HORIZONTAL;
  tcolumn.setEditable(false);
  c.gridx = 3;
  c.gridy = 0;
  add(tcolumn, c);
  toutput = new JTextField("output");
  c.weightx = 0.2;
  c.fill = GridBagConstraints.HORIZONTAL;
  toutput.setEditable(false);
  c.gridx = 4;
  c.gridy = 0;
  add(toutput, c);
  
  error = new JTextField();
  error.setEditable(false);
  error.setForeground(Color.RED);
  c.fill = GridBagConstraints.HORIZONTAL;
  c.gridwidth=2;
  c.gridx = 0;
  c.gridy = 2;
  add(error, c);
  
  input1 = new JTextField("in1");
  c.weightx = 0.2;
  c.fill = GridBagConstraints.HORIZONTAL;
  c.gridwidth=1;
  c.gridx = 0;
  c.gridy = 1;
  add(input1, c);


  input2 = new JTextField("in2");
  c.fill = GridBagConstraints.HORIZONTAL;
  c.weightx = 0.2;
  c.gridx = 1;
  c.gridy = 1;
  add(input2, c);


  
  //button = new JButton("Long-Named Button 4");
  //c.fill = GridBagConstraints.HORIZONTAL;
  //c.ipady = 40;      //make this component tall
  //c.weightx = 0.0;
  //c.gridwidth = 3;
  //c.gridx = 0;
  //c.gridy = 1;
  //pane.add(button, c);

  //button = new JButton("5");
  //c.fill = GridBagConstraints.HORIZONTAL;
  //c.ipady = 0;       //reset to default
  //c.weighty = 1.0;   //request any extra vertical space
  //c.anchor = GridBagConstraints.PAGE_END; //bottom of space
  //c.insets = new Insets(10,0,0,0);  //top padding
  //c.gridx = 1;       //aligned with button 2
  //c.gridwidth = 2;   //2 columns wide
  //c.gridy = 2;       //third row
  //add(button, c);
  box =new JComboBox(gates);
  c.fill = GridBagConstraints.HORIZONTAL;
  c.weightx = 0.4;
  c.gridx = 2;
  c.gridy = 1;
  add(box,c);
  
  column = new JTextField("Column");
  c.fill = GridBagConstraints.HORIZONTAL;
  c.weightx = 0.2;
  c.gridx = 3;
  c.gridy = 1;
  add(column, c);
  
  
  output = new JTextField("out");
  c.fill = GridBagConstraints.HORIZONTAL;
  c.weightx = 0.2;
  c.gridx = 4;
  c.gridy = 1;
  add(output, c);
  
  nextGate = new JButton("Next Gate");
  nextGate.addActionListener(new ActionListener(){
   public void actionPerformed(ActionEvent pushingBtNg)
    {try{
	gate[box.getSelectedIndex()].compute(Board.board[Integer.parseInt(column.getText())][Integer.parseInt(input1.getText())],
    Board.board[Integer.parseInt(column.getText())][Integer.parseInt(input2.getText())],
    Board.board[Integer.parseInt(column.getText())+1][Integer.parseInt(output.getText())]);
    Logic.circuit[counter][0]=gates[box.getSelectedIndex()];
    Logic.circuit[counter][1]=column.getText();
    Logic.circuit[counter][2]=input1.getText();
    Logic.circuit[counter][3]=input2.getText();
    Logic.circuit[counter][4]=output.getText();
    counter++;
    
	
    pinput1.setText(pinput1.getText()+input1.getText()+"\n");
    pinput2.setText(pinput2.getText()+input2.getText()+"\n");
    pgate.setText(pgate.getText()+gates[box.getSelectedIndex()]+"\n");
    pcolumn.setText(pcolumn.getText()+column.getText()+"\n");
    poutput.setText(poutput.getText()+output.getText()+"\n");
    error.setText("");
    pack();}
    catch(NumberFormatException e){ error.setText("Invalid Input");}
    }
   }
  );
  
  c.fill = GridBagConstraints.HORIZONTAL;
  c.weightx = 0.2;
  c.gridx = 4;
  c.gridy = 2;
  add(nextGate, c);
  
  pinput1 = new JTextArea("");
  pinput1.setEditable(false);
  c.fill = GridBagConstraints.HORIZONTAL;
  c.weightx = 0.2;
  c.gridx = 0;
  c.gridy = 3;
  add(pinput1, c);
  
  pinput2 = new JTextArea("");
  pinput2.setEditable(false);
  c.fill = GridBagConstraints.HORIZONTAL;
  c.weightx = 0.2;
  c.gridx = 1;
  c.gridy = 3;
  add(pinput2, c);
  
  pgate = new JTextArea("");
  pgate.setEditable(false);
  c.fill = GridBagConstraints.HORIZONTAL;
  c.weightx = 0.4;
  c.gridx = 2;
  c.gridy = 3;
  add(pgate, c);
  
  pcolumn = new JTextArea("");
  pcolumn.setEditable(false);
  c.fill = GridBagConstraints.HORIZONTAL;
  c.weightx = 0.2;
  c.gridx =3;
  c.gridy = 3;
  add(pcolumn, c);
  
  poutput = new JTextArea("");
  poutput.setEditable(false);
  c.fill = GridBagConstraints.HORIZONTAL;
  c.weightx = 0.2;
  c.gridx = 4;
  c.gridy = 3;
  add(poutput, c);
  
  finish = new JButton("Finish");
  finish.addActionListener(new ActionListener(){
   public void actionPerformed(ActionEvent pushingBtNg)
    {Circuitgui.refresh();}
   }
  );
  c.fill = GridBagConstraints.HORIZONTAL;
  //c.anchor = GridBagConstraints.PAGE_END;
  c.weightx = 0.2;
  c.gridx = 4;
  c.gridy = 4;
  add(finish, c);
  
  save = new JButton("Save");
  save.addActionListener(new ActionListener(){
   public void actionPerformed(ActionEvent pushingBtNg)
    {File.save();}
   }
  );
  c.fill = GridBagConstraints.HORIZONTAL;
  //c.anchor = GridBagConstraints.PAGE_END;
  c.weightx = 0.2;
  c.gridx = 0;
  c.gridy = 4;
  add(save, c);
  
  load = new JButton("Load");
  load.addActionListener(new ActionListener(){
   public void actionPerformed(ActionEvent pushingBtNg)
    {File.load();
    pack();}
   }
  );
  c.fill = GridBagConstraints.HORIZONTAL;
  //c.anchor = GridBagConstraints.PAGE_END;
  c.weightx = 0.2;
  c.gridx = 1;
  c.gridy = 4;
  add(load, c);
  
  newcircuit = new JButton("New");
  newcircuit.addActionListener(new ActionListener(){
   public void actionPerformed(ActionEvent pushingBtNg)
    {Logic.b.set();
    pinput1.setText("");
    pinput2.setText("");
    pgate.setText("");
    pcolumn.setText("");
    poutput.setText("");
    }
   }
  );
  c.fill = GridBagConstraints.HORIZONTAL;
  //c.anchor = GridBagConstraints.PAGE_END;
  c.weightx = 0.2;
  c.gridx = 2;
  c.gridy = 4;
  add(newcircuit, c);
  
  this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  this.pack();
  this.setVisible(true);
  
 }
}