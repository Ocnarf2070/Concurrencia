package prFumadores;

public class Mesa {
	private int ingr=-1;
	private boolean finFumar=true;
	
	public synchronized void nuevoIngr(int nIngr) throws InterruptedException{
		while(!finFumar||ingr!=1)wait();
		ingr=nIngr;
		System.out.println("Agente no pone "+ingr);
		notifyAll();
				
	}
	public synchronized void qFumar(int id) throws InterruptedException{
		while(ingr!=id)wait();
		System.out.println();
		ingr=-1;
		finFumar=false;
	}
	public synchronized void finFumar(int id){
		 finFumar = true;
		notifyAll();
	}
}
