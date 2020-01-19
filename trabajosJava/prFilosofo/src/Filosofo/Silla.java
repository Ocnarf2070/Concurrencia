package Filosofo;
import java.util.concurrent.*;
public class Silla {
	private int sLibre=4;
	//private Semaphore sem=new Semaphore(1,true);
	private Semaphore haySillas=new Semaphore(1, true);
	private Semaphore mutex=new Semaphore(1,true);
	public void qSilla(int id) throws InterruptedException{
		haySillas.acquire();
		mutex.acquire();
		sLibre--;
		if(sLibre>0) haySillas.release();
		mutex.release();
	}
	public void dSilla(int id) throws InterruptedException{
		mutex.acquire();
		sLibre++;
		if(sLibre==1)haySillas.release();
		mutex.release();
		
	}
}
