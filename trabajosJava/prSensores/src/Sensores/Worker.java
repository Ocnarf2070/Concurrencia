package Sensores;

import java.util.Random;

public class Worker extends Thread{
	private Mediciones m;
	private Random r=new Random();
	public Worker(Mediciones m){
		this.m=m;
	}
	public void run(){
		while(true){
			try {
				m.leerMediciones();
				Thread.sleep(r.nextInt(200));
				m.finTarea();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
