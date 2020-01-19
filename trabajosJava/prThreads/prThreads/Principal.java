package prThreads;

public class Principal {

	public static void main(String[] args) {
		Escritor e1=new Escritor(1,'A');
		Escritor e2 = new Escritor(2,'B');
		Thread th_e1=new Thread(e1);
		Thread th_e2=new Thread(e2);
		th_e1.start();//e1.run();
		th_e2.start();
	}

}
