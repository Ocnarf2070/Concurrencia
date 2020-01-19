package Sensores;

import java.util.concurrent.Semaphore;

public class Mediciones {
	private int n=0;
	private Semaphore mutex=new Semaphore(1,true);
	private Semaphore esperaM=new Semaphore(0,true);
	private Semaphore esperaFinT=new Semaphore(0,true);
	public void nuevaMedicion(int id) throws InterruptedException{
		mutex.acquire();
		n++;
		System.out.println("Sensor "+id+" deja dato "+n);
		if(n==3)esperaM.release();
		mutex.release();
		esperaFinT.acquire();
	}
	public void leerMediciones() throws InterruptedException{
		esperaM.acquire();
		mutex.acquire();
		System.out.println("Trabajor lee "+n+" datos" );
		mutex.release();
	}
	public void finTarea(){
		System.out.println("Trabajador finaliza tarea");
		for(int i=0;i<3;i++)esperaFinT.release();
		System.exit(0);
	}
	
}
