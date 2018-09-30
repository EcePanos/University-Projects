import java.awt.Button;


public class Weakling extends Thread {
	Button seat= new Button();
	String id;
	//boolean hairIsCut=false;
	//boolean waiting=false;
	Weakling(String id){
		this.id=id;
		seat.setBounds(SleepingBarber.gui.pos[Integer.parseInt(id)][0].x,
				SleepingBarber.gui.pos[Integer.parseInt(id)][0].y, 20, 20);
		seat.setLabel(id);
		SleepingBarber.gui.add(seat);
	}
	
	public void run(){
		while(true){
			customerWait();
			goToDoor();
			customerWait();
			goToWaitingRoom();
			cutMyHair();
			//while(hairIsCut==false){
				customerWait();
			//}
			
			//goToBarber();
			SleepingBarber.b.cutHair(this);
			
			//customerWait();
			//hairIsCut=false;
			//goToBase();
				
		}
	}
	public void cutMyHair(){
		System.out.println("Customer "+id+" wants a haircut");
	}
	void customerWait(){
		try{
			sleep((long) (Math.random()*3000));
			
		}
		catch(InterruptedException e){
			e.printStackTrace();
		}
	}
	public void goToBase(){
		Barber.rest();
		seat.setBounds(SleepingBarber.gui.pos[Integer.parseInt(id)][0].x,
				SleepingBarber.gui.pos[Integer.parseInt(id)][0].y, 20, 20);
	}
	void goToDoor(){
		seat.setBounds(SleepingBarber.gui.pos[Integer.parseInt(id)][1].x,
				SleepingBarber.gui.pos[Integer.parseInt(id)][1].y, 20, 20);
		}
	void goToWaitingRoom(){
		WaitingRoom.checkSeat();
		//WaitingRoom.queue.add(this);
		seat.setBounds(SleepingBarber.gui.pos[Integer.parseInt(id)][2].x,
				SleepingBarber.gui.pos[Integer.parseInt(id)][2].y, 20, 20);
	}
	public void goToBarber(){
		
		WaitingRoom.getUp();
		Barber.work();
		seat.setBounds(SleepingBarber.gui.pos[Integer.parseInt(id)][3].x,
				SleepingBarber.gui.pos[Integer.parseInt(id)][3].y, 20, 20);
	}
}
	