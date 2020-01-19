package aseos;

import java.util.concurrent.locks.*;

public class AseosMonitorJus {
	private Lock l = new ReentrantLock();
	private Condition espCliente=l.newCondition();
	private Condition espEquipo=l.newCondition();
	private boolean estaEquipo=false,equipoEsperando=false;
	private int nCliente=0;
	/**
	 * Utilizado por el cliente id cuando quiere entrar en los aseos
	 * CS Version injusta: El cliente espera si el equipo de limpieza está trabajando
	 * CS Version justa: El cliente espera si el equipo de limpieza está trabajando o
	 * está esperando para poder limpiar los aseos
	 * @throws InterruptedException 
	 * 
	 */
	public void entroAseo(int id) throws InterruptedException{
		l.lock();
		try{
			while(estaEquipo||equipoEsperando){
				espCliente.await();
			}
			nCliente++;
		}finally{
			l.unlock();
		}
	}

	/**
	 * Utilizado por el cliente id cuando sale de los aseos
	 * @throws InterruptedException 
	 * 
	 */
	public void salgoAseo(int id) throws InterruptedException{
		l.lock();
		try{
		nCliente--;
		if(nCliente==0)espEquipo.signal();
		}finally{
			l.unlock();
		}
	}
	
	/**
	 * Utilizado por el Equipo de Limpieza cuando quiere entrar en los aseos 
	 * CS: El equipo de trabajo está solo en los aseos, es decir, espera hasta que no
	 * haya ningún cliente.
	 * @throws InterruptedException 
	 * 
	 */
    public void entraEquipoLimpieza() throws InterruptedException{
		l.lock();
		try{
			equipoEsperando=true;
			while(nCliente>0){
				espEquipo.await();
			}
			estaEquipo=true;
		}finally{
			l.unlock();
		}

	}
    
    /**
	 * Utilizado por el Equipo de Limpieza cuando  sale de los aseos 
	 * 
	 * 
	 */
    public void saleEquipoLimpieza(){
		l.lock();
		try{
			estaEquipo=false;
			equipoEsperando=false;
			espCliente.signalAll();
		}finally{
			l.unlock();
		}

	}
}
