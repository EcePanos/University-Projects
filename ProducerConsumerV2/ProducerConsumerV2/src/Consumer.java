
class Consumer extends Thread 
{
	private Buffer b;
	public Consumer(Buffer b)
	{
		this.b = b;
	}
	
	public void run() 
	{
		
		for(int i=0;i<24;i++) 
		{
				// Consumer's Critical Section		
				String good = b.get();
				System.out.println("Consumer retrieved " + good);
				try 
				{
					Thread.sleep((int)(Math.random() * 3000));
				}
				catch(InterruptedException e) 
				{
					System.err.println(e.toString());
				}
			
			
		}
	}
}