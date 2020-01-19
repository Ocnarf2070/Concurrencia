package prJardin;

public class Puertas extends Thread {
	private Contador c;
	public Puertas(Contador c){
		this.c=c;
	}
	public void run(){
		for(int i=0;i<1000;i++){
			c.inc();
		}
	}
}
