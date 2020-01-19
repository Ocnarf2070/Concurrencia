package Semaforo;

import java.util.concurrent.Semaphore;

/**
 * Clase del ascensor que tiene capacidad para una persona
 */
public class Ascensor extends Thread{
	private int sig = 1; // para saber si el ascensor sube o baja
	private int planta = 0; //planta en la que se encuentra el ascensor
	private int numPlantas;
	private Semaphore mutex = new Semaphore(1,true);
	private Semaphore esperaCliente=new Semaphore(1, true);
	private Semaphore esperaAscensor= new Semaphore(0,true);
	/*private Semaphore lleno = new Semaphore(0,true);
	private Semaphore movimiento=new Semaphore(0, true);
	private Semaphore llegada=new Semaphore(0,true);
	private Semaphore espera=new Semaphore(0, true);*/
	private boolean hayCliente=false;
	public Ascensor(int C){
	// C es el numero de plantas del edificio
		numPlantas = C;
	
	}
	

	// Cliente id  espera el ascensor desde origen
	public  void clienteEsperaAscensor(int origen,int id) throws InterruptedException{
		/*mutex.acquire();
		System.out.println("Cliente "+id+" espera en "+origen);
		while(planta!=origen){
			espera.acquire();
			//lleno.acquire();
		}
		mutex.release();*/
		System.out.println("Cliente "+id+" espera en "+origen);

		while(planta!=origen || hayCliente){
			esperaCliente.acquire();
			esperaCliente.release();
		}
		mutex.acquire();
		hayCliente=true;
		mutex.release();
		
	}
	
	//el cliente id sube al ascensor, actualiza el destino
	public  void clienteSubeAscensor(int destino, int id) throws InterruptedException{
		/*mutex.acquire();
		System.out.println("Cliente "+id+" quiere ir a "+destino);
		lleno.acquire();*/
		//espera.release();
		esperaAscensor.acquire();
		mutex.acquire();
		System.out.println("Cliente "+id+" quiere ir a "+destino);
		mutex.release();
		esperaAscensor.release();
		
	}
	
	// El cliente espera hasta llegar a su planta y baja del ascensor
		public  void clienteBajaAscensor(int destino, int id) throws InterruptedException{
			esperaAscensor.acquire();
			mutex.acquire();
			
			System.out.println("Cliente "+id+" llego a su parada");
			hayCliente=false;
			mutex.release();
			esperaAscensor.release();
	
	}

	
	//Ascensor llega a una planta y si lleva a un cliente con destino a
	//planta lo deja bajar
	public  void ascensorLlegaPlantaBajar(int planta) throws InterruptedException{
		esperaAscensor.acquire();
		mutex.acquire();
		System.out.println("Ascensor llego a su destino");
		mutex.release();
		esperaAscensor.release();
	}
			
	// el Ascensor espera a que se baje cliente, si es el caso
	public  void ascensorEsperaBajarCliente(int planta) throws InterruptedException{

		System.out.println("Ascensor espera a Cliente");
		esperaAscensor.acquire();
		mutex.acquire();
		esperaAscensor.release();
		mutex.release();
		
		}		
	
	
	//Ascensor deja entrar a un nuevo cliente si esta vacio
	public  void ascensorLlegaPlantaSubir(int planta) throws InterruptedException{
			esperaAscensor.acquire();
			mutex.acquire();
			StringBuilder sb =new StringBuilder();
			sb.append(b);
			
		}
		
	//Ascensor espera subir a un cliente, si esta vacio
	public  void ascensorEsperaSubirCliente() throws InterruptedException{
			}
			
		
			
	//s�lo sirve para que se vayan actualizando las plantas
	//el ascensor sube hasta que llega al �ltimo piso, y luego
	//baja hasta que llega a la planta 0, y asi sucesivamente
	private void siguientePiso() throws InterruptedException{
			Thread.sleep(1000);
			if (planta==numPlantas-1) sig = -1;
			if (planta == 0) sig = 1;
			planta = planta + sig;
			System.out.println("Ascensor est� en la planta "+planta);
	}
		
		

		
		
	public void run(){
	
		while (true){
			try {
				ascensorLlegaPlantaBajar(planta);
				ascensorEsperaBajarCliente(planta);
				ascensorLlegaPlantaSubir(planta);
				ascensorEsperaSubirCliente();
				siguientePiso();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
		}
	}
	

}	
	
	