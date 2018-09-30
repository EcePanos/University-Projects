import java.awt.Button;


public class SleepingBarber {
	
	static BarberGui gui=new BarberGui();
	static Barber b=new Barber();
		public static void main(String[] args){
		Weakling customer0=new Weakling("0");
		Weakling customer1=new Weakling("1");
		Weakling customer2=new Weakling("2");
		Weakling customer3=new Weakling("3");
		Weakling customer4=new Weakling("4");
		Weakling customer5=new Weakling("5");
		Weakling customer6=new Weakling("6");
		Weakling customer7=new Weakling("7");
		Weakling customer8=new Weakling("8");
		Weakling customer9=new Weakling("9");
		
		customer0.start();
		customer1.start();
		customer2.start();
		customer3.start();
		customer4.start();
		customer5.start();
		customer6.start();
		customer7.start();
		customer8.start();
		customer9.start();
		}
}
