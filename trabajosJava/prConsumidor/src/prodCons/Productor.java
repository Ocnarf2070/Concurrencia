package prodCons;

public class Productor extends Thread{
	private Buffer b;
	public Productor(Buffer b){
		this.b = b;
	}
	
	
	public void run(){
		boolean fin=false;
		int i=0;
		while(!this.isInterrupted()&&!fin){
			//generando el nuevo dato
			try {
				b.almacenar(i);
				i++;
			} catch (InterruptedException e) {
				fin=true;
			}
		}
	}

}
