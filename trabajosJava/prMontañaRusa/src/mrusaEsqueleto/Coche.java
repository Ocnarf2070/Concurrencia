package mrusaEsqueleto;





import java.util.concurrent.locks.*;

public class Coche extends Thread{
	
	private Lock l = new ReentrantLock(true);
	private boolean cocheLleno = false;
	private Condition cCocheLleno = l.newCondition();
	
	private boolean pAbierta = true;
	private Condition cpAbierta = l.newCondition();
	
	private boolean finViaje = false;
	private Condition cfinViaje = l.newCondition();
	
	private int tam;
	private int numPas = 0;
	
	public Coche(int tam){
		this.tam = tam;
	}
	
	public Coche(){
		tam = 5;
	}
	
	
	public void subir(int id) throws InterruptedException{
		// id del pasajero que se sube al coche
		l.lock();
		try{
			while (!pAbierta)
				cpAbierta.await();
			
			numPas++;
			if (numPas==tam){
				pAbierta = false; //no dejo entrar a más
				cocheLleno = true;
				cCocheLleno.signal();
			}
			
		}finally{
			l.unlock();
		}
		
	}
	
	public void bajar(int id) throws InterruptedException{
		// id del pasajero que se baja del coche
		l.lock();
		try{
			
			
			
		}finally{
			l.unlock();
		}
	}

	
	private void esperaLleno() throws InterruptedException{
		//el coche espera a que este lleno para dar una vuelta
		l.lock();
		try{
			
			
			
		}finally{
			l.unlock();
		}
	}
	
	public void run(){
		while (true)
			try{
				this.esperaLleno();
				
			}catch (InterruptedException ie){}
		
		
	}
}
