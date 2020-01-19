package Filosofo;

import java.util.concurrent.Semaphore;

public class Tenedor {
	private Semaphore mutex = new Semaphore(1, true);
	private int i;
	public Tenedor(int i){
		this.i=i;
	}
	public void qTenedor(int id) throws InterruptedException{
		mutex.acquire();
		System.out.println("Filosofo "+id+" tiene el tenedor "+i);
	}
	public void dTenedor(int id){
		mutex.release();
		System.out.println("Filosofo "+id+" suelta el tenedor "+i);
	}
}
