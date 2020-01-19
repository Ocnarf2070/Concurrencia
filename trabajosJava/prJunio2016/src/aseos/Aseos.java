package aseos;

import java.util.concurrent.*;

public class Aseos {
	private int numCliente=0;
	private Semaphore mutex = new Semaphore(1);
	private Semaphore aseoOcupado=new Semaphore(1);	
	
	/**
	 * Utilizado por el cliente id cuando quiere entrar en los aseos
	 * CS Version injusta: El cliente espera si el equipo de limpieza está trabajando
	 * CS Version justa: El cliente espera si el equipo de limpieza está trabajando o
	 * está esperando para poder limpiar los aseos
	 * @throws InterruptedException 
	 * 
	 */
	public void entroAseo(int id) throws InterruptedException{
		mutex.acquire();
		numCliente++;
		if(numCliente==1)aseoOcupado.acquire();
		System.out.println("Entra cliente. Hay "+numCliente);
		mutex.release();
	}

	/**
	 * Utilizado por el cliente id cuando sale de los aseos
	 * @throws InterruptedException 
	 * 
	 */
	public void salgoAseo(int id) throws InterruptedException{
	mutex.acquire();
	numCliente--;
	if(numCliente==0)aseoOcupado.release();
	System.out.println("Sale cliente. Quedan "+numCliente);
	mutex.release();
	}
	
	/**
	 * Utilizado por el Equipo de Limpieza cuando quiere entrar en los aseos 
	 * CS: El equipo de trabajo está solo en los aseos, es decir, espera hasta que no
	 * haya ningún cliente.
	 * @throws InterruptedException 
	 * 
	 */
    public void entraEquipoLimpieza() throws InterruptedException{
		aseoOcupado.acquire();		
		System.out.println("Entra Limpieza");

	}
    
    /**
	 * Utilizado por el Equipo de Limpieza cuando  sale de los aseos 
	 * 
	 * 
	 */
    public void saleEquipoLimpieza(){
		aseoOcupado.release();
		System.out.println("Sale limpieza");

	}
}
