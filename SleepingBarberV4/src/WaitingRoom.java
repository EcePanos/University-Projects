import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.Semaphore;

public class WaitingRoom {
	//public static Queue<Weakling> queue=new LinkedList<Weakling>();
	
	public static int availableSeats=4;
	public static Semaphore s=new Semaphore(availableSeats,true);
	WaitingRoom(){
		
	}
	public static void checkSeat(){
		try {
			s.acquire();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public static void getUp(){
		s.release();
	}
}
