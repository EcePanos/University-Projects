
public class Producer extends Thread
{
	private Buffer b;
	private String product;
	
	public Producer(Buffer b)
	{
		this.b = b;
	}
	
	public void run() 
	{
		
		for(int i=0;i<12;i++) 
		{
			
			try 
			{
				Thread.sleep((int)(Math.random() * 3000));
			}
			catch(InterruptedException e) 
			{
				System.err.println(e.toString());
			}
			// Producer's Critical Section 
			while(b.getState() == false)
			{
				
			}
			product = "'" + Integer.toString(i) + "'" + Integer.toString(i);
			b.put(i, Integer.toString(i));	
			System.out.println("Producer set buffer to " + product);
			//End of Producer's Critical Section
			
		}
	}
}
