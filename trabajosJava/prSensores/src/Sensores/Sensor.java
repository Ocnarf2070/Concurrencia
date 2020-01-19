package Sensores;

import java.util.Random;

public class Sensor extends Thread{
	private static Random r=new Random();
	private int id;
	private Mediciones m;
	public Sensor (int id,Mediciones m){
		this.m=m;
		this.id=id;
	}
	public void run(){
		while(true){
			try{
				Thread.sleep(r.nextInt(100));
				m.nuevaMedicion(id);
			}catch(InterruptedException msg){
				msg.printStackTrace();
			}
		}
	}
}
