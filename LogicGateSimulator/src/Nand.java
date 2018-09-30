
public class Nand extends Gate {
	
	public void compute(Pin In1,Pin In2,Pin Out){
		Out.set(!(In1.get()&&In2.get()));
		System.out.println(Out.get());
	}

}