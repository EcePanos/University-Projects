import java.awt.Button;
import java.util.concurrent.Semaphore;

public class Barber{
	static Button barberIcon=new Button();
	static int haircuts=0;
	//static int barberSeats=1;
	//public static Semaphore signal=new Semaphore(barberSeats,true);
	Barber(){
		barberIcon.setBounds(215,200, 20, 40);
		barberIcon.setLabel("B");
		SleepingBarber.gui.add(barberIcon);
	}
	public synchronized void cutHair(Weakling p){
			work();
			p.goToBarber();
			System.out.println("Barber is cutting customer "+p.id+"'s hair");
			try {
				p.sleep((long) (Math.random()*5000));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			haircuts++;
			p.goToBase();
			
			if(haircuts<5){
				rest();
			}
			else{
				sleep();
			}
		
	}
	static void work(){
		/*
		try {
			signal.acquire();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		*/
		barberIcon.setBounds(271,57, 30, 30); 
	}
	static void rest(){
		//signal.release();
		/*
		if(haircuts>=5){
			sleep();
		}
		*/
		barberIcon.setBounds(215,200, 20, 40);
	}
	static void sleep(){
		//signal.release();
		barberIcon.setBounds(215,200, 20, 40);
		System.out.println("Barber is sleeping");
		try {
			Thread.sleep(5000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		haircuts=0;
	}
}
