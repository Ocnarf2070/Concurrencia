import prodCons.*;
public class Principal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Buffer b = new Buffer();
		Productor p = new Productor(b);
		Consumidor c = new Consumidor(b);
		p.start();c.start();
		try{
			Thread.sleep(2000);
			p.interrupt();
			c.interrupt();
		}catch(InterruptedException msg){
			
		}
	}

}
