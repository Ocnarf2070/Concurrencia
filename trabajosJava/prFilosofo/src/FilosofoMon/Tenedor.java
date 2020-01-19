package FilosofoMon;

public class Tenedor {
	private boolean libre = true;
	private int i;
	public Tenedor(int i){
		this.i=i;
	}
	public synchronized void qTenedor(int id) throws InterruptedException{
		while(!libre)wait();
		System.out.println("Filosofo "+id+" tiene el tenedor "+i);
		libre=false;
	}
	public synchronized void dTenedor(int id){
		System.out.println("Filosofo "+id+" suelta el tenedor "+i);
		libre=true;
		notifyAll();
	}
}
