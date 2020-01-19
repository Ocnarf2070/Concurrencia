package Filosofo;

import java.util.Random;

public class Filosofo extends Thread {
	private int id;
	private Tenedor izq,dcha;
	private Random r=new Random();
	private Silla sillas;
	public Filosofo(int id, Tenedor izq, Tenedor dcha,Silla sillas){
		this.id=id;
		this.dcha=dcha;
		this.izq=izq;
		this.sillas=sillas;
	}
	public void run(){
		while(true){
			try {
				//Thread.sleep(r.nextInt(200));
				sillas.qSilla(id);
				izq.qTenedor(id);
				dcha.qTenedor(id);
				//Thread.sleep(r.nextInt(100));
				izq.dTenedor(id);
				dcha.dTenedor(id);
				sillas.dSilla(id);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		
		}
	}
}
