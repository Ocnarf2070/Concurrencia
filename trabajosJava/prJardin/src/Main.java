import prJardin.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Contador c= new Contador();
		Puertas p1 = new Puertas(c);
		Puertas p2 = new Puertas(c);
		p1.start();
		p2.start();
		
		try {
			p1.join();
			p2.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
