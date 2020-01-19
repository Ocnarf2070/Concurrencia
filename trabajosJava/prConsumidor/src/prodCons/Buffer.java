package prodCons;

public class Buffer {
	
	private int N = 5;
	private int[] buffer = new int[N];
	private int i = 0, j = 0;
	private int numElem = 0;
	
	public synchronized void almacenar(int dato) throws InterruptedException{
		while (numElem == N)
			wait();
		System.out.println("Productor "+dato);
		buffer[i] = dato;
		i = (i+1)%N;
		numElem++;
	
		notify();
	}
	public synchronized int extraer() throws InterruptedException{
		while (numElem == 0)
			wait();
		
		int dato = buffer[j];
		j = (j+1)%N;
		numElem--;
		
		notify();
		return dato;
	}
	
	public synchronized int numElem(){
		return numElem;
	}
}
