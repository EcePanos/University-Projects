
class Buffer 
{
	
	private int valueInt;
	private String valueString;
	private boolean empty = true;
	
	
	public synchronized void put(int val, String val1)
	{
		while(!empty)
		{
			try {
				wait();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		valueInt = val;
		valueString = val1;
		empty = false;
		notifyAll();
	}
	
	public synchronized String get()
	{
		while(empty) 
		{
			try
			{
				wait();
			}
			catch(InterruptedException e) 
			{
				System.err.println("Exception:" + e.toString());
			}
		}
		empty = true;
		notifyAll();
		return  "'" + (Integer.toString(valueInt)) + "'" + valueString;
	}
	
	public boolean getState()
	{
		return empty;
	}
}