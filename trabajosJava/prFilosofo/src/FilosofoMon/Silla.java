package FilosofoMon;
public class Silla {
	private int sLibre=4;
	
	public synchronized void qSilla(int id) throws InterruptedException{
		while(sLibre==0)wait();
		sLibre--;
	}
	public synchronized void dSilla(int id) throws InterruptedException{
		sLibre++;
		if(sLibre==1)notify();
		
	}
}
