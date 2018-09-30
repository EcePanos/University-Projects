
class Buffer 
{
	
	private int valueInt;
	private String valueString;
	private boolean empty = true;
	
	
	public void put(int val, String val1)
	{
		valueInt = val;
		valueString = val1;
		empty = false;
	}
	
	public String get()
	{
		empty = true;
		return  "'" + (Integer.toString(valueInt)) + "'" + valueString;
	}
	
	public boolean getState()
	{
		return empty;
	}

}

