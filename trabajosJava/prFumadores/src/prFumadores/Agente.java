package prFumadores;

import java.util.Random;

public class Agente {
	private Mesa BlackMesa;
	private Random r = new Random();
	public Agente(Mesa mesa){
		BlackMesa=mesa;
	}
	public void run(){
		while(true){
			try {
				BlackMesa.nuevoIngr(r .nextInt(3));
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
	}
}
