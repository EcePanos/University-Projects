import java.util.InputMismatchException;
import java.util.Scanner;


public class Board {
 public static Pin board[][];
 public static int columns,rows;
 public void set(){
  Scanner sc = new Scanner(System.in);
  //int columns,rows;
  System.out.println("\nNumber of Columns:");
  try{
  columns=sc.nextInt();}
  catch(InputMismatchException e){}
  System.out.println("Number of Rows:");
  try{
  rows=sc.nextInt();}
  catch(InputMismatchException e){}
  
  create();
  for(int i=0;i<rows;i++)
  {
   System.out.println("Give input "+i+":");
   try{
   boolean t=sc.nextBoolean();
   board[0][i].set(t);}
   catch(InputMismatchException e){}
   
  }
  
  new Circuitgui();
  sc.close();
 }
 public static void get(){
  for(int i=0;i<rows;i++)
  {
   for(int j=0;j<columns;j++)
   { 
    System.out.print(board[j][i].get()+" ");
   }
   System.out.println();
  }
 }
 public static void create(){
	  board=new Pin[columns][rows];
	  
	  for(int i=0;i<rows;i++)
	  {
	   for(int j=0;j<columns;j++)
	   { 
	    board[j][i]=new Pin();
	   }
	  }
	  
	 }
}