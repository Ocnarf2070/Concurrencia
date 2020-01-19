package prFumadores;

public class Fumador extends Thread{
	private Mesa BlackMesa;
	private int id;
	public Fumador(int id, Mesa mesa){
		BlackMesa=mesa;
		this.id=id;
	}
	
}	
