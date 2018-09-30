import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class File {
	 public static void save(){
		  try {
		   PrintWriter file=new PrintWriter("logicircuit.txt");
		   file.println("Circuit:\n");
		   file.println("Columns: "+Board.columns+" Rows: "+Board.rows);
		   file.print("\t");
		   int i;
		for(i=0;i<Board.columns;i++)
		    file.print(i+"\t");
		   file.println();
		   int j;
		for(i=0;i<Board.rows;i++)
		   {   
		    file.print(i+"\t");
		    for(j=0;j<Board.columns;j++)
		    { 
		     file.print(Board.board[j][i].get()+"\t");
		    }
		    file.println();
		   }
		   
		   file.println("Gates:\n");
		   file.println("\tGate:\tColumn:\tInput1:\tInput2\tOutput:\n");
		   for(i=0;i<Lgsgui.counter;i++)
		   {   
		    file.print(i+"\t");
		    for(j=0;j<5;j++)
		    { 
		     file.print(Logic.circuit[i][j]+"\t");
		    }
		    file.println();
		   }
		   file.close();
		  } catch (FileNotFoundException e) {
		   // TODO Auto-generated catch block
		   e.printStackTrace();
		  }
		  
		 }
	public static void load(){
		  String line = null;
		  int counter=0;
		  try {
			Lgsgui.pinput1.setText("");
			Lgsgui.pinput2.setText("");
			Lgsgui.pgate.setText("");
			Lgsgui.pcolumn.setText("");
			Lgsgui.poutput.setText("");
		   FileReader file=new FileReader("logicircuit.txt");
		         BufferedReader bufferedReader = new BufferedReader(file);
		         try {
		    while((line = bufferedReader.readLine()) != null) {
		        String[] words=line.split("\\s");
		        try{
		         if(words[0].equals("Columns:"))
		         {
		          Board.columns=Integer.parseInt(words[1]);
		          Board.rows=Integer.parseInt(words[3]);
		          Board.create();
		         }
		         if(words[1].equals("true")||words[1].equals("false"))
		         {
		          for(int i=0;i<Board.columns;i++)
		          {
		           Logic.b.board[i][counter].set(Boolean.valueOf(words[i+1]));
		          }
		          counter++;
		         }
		         if(words[1].equals("And")||words[1].equals("Or")||words[1].equals("Not")||words[1].equals("Nor")||
		           words[1].equals("Nand")||words[1].equals("Xor")||words[1].equals("Xnor"))
		         {
		       Lgsgui.pinput1.setText(Lgsgui.pinput1.getText()+words[3]+"\n");
		       Lgsgui.pinput2.setText(Lgsgui.pinput2.getText()+words[4]+"\n");
		       Lgsgui.pgate.setText(Lgsgui.pgate.getText()+words[1]+"\n");
		       Lgsgui.pcolumn.setText(Lgsgui.pcolumn.getText()+words[2]+"\n");
		       Lgsgui.poutput.setText(Lgsgui.poutput.getText()+words[5]+"\n");
		         }
		        }
		        catch(Exception e)
		        {}
		    }


		    new Circuitgui();
		   } catch (IOException e) {
		    // TODO Auto-generated catch block
		    e.printStackTrace();
		   }    
		         
		  } catch (FileNotFoundException e) {
		   // TODO Auto-generated catch block
		   e.printStackTrace();
		  }
	}
}
