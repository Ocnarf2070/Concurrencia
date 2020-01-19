import Lago.*;
public class Principal2 {
	public static void main(String[] args) {
		Lago lago = new Lago();
		Rio rio=new Rio(lago);
		Presa pr0=new Presa(lago,0);
		Presa pr1=new Presa(lago, 1);
		rio.start();
		pr0.start();
		pr1.start();
	}
}
