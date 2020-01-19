package prodCons;

public class Consumidor extends Thread{
	private Buffer b;
	public Consumidor(Buffer b){
		this.b = b;
	}
	
	
	public void run(){
		boolean fin=false;
		while((!this.isInterrupted()&&!fin)||b.numElem()>0){	
			try {
				System.out.println("Consume: "+b.extraer());
			} catch (InterruptedException e) {
				fin=true;
			}
			//consumiendo el nuevo dato
		}
	}
}
