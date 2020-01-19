package Pajaros;

import java.util.concurrent.Semaphore;

public class Nido {
	private int n=0;
	private Semaphore mutex= new Semaphore(1, true);
	private Semaphore esperaB=new Semaphore(0, true);
	private Semaphore esperaP=new Semaphore(1, true);
	private int B=5;
	public void come(int id) throws InterruptedException{
		esperaB.acquire();
		mutex.acquire();
		n--;
		if(n>0)esperaB.release();
		if(n==B-1)esperaP.release();
		mutex.release();
	}
	public void nuevoBicho(int id) throws InterruptedException{
		esperaP.acquire();
		mutex.acquire();
		n++;
		if(n<B)esperaP.release();
		if(n==1)esperaP.release();
		mutex.release();
	}
}
