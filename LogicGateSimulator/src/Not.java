
public class Not extends Gate {
	
	public void compute(Pin In1,Pin In2,Pin Out){
		Out.set(!In1.get());
		System.out.println(Out.get());
	}

}