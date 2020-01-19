package semaforosEsqueleto;

import java.util.concurrent.*;
public class Mesa {
	private int numJug=0,N,ganador=N,numCara=0,numCruz=0;
	private boolean [] moneda;
	private Semaphore mutex=new Semaphore(1);
	private Semaphore nueva=new Semaphore(1);
	private Semaphore espera=new Semaphore(0);
	public Mesa(int N){
		this.N=N;
		moneda=new boolean [N];
	}
	
	
	
	/**
	 * 
	 * @param id del jugador que llama al método
	 * @param cara : true si la moneda es cara, false en otro caso
	 * @return un valor entre 0 y N. Si devuelve N es que ningún jugador 
	 * ha ganado y hay que repetir la partida. Si  devuelve un número menor que N, es el id del
	 * jugador ganador.
	 * 
	 * Un jugador llama al método nuevaJugada cuando quiere poner
	 * el resultado de su tirada (cara o cruz) sobre la mesa.
	 * El jugador deja su resultado y, si no es el último, espera a que el resto de 
	 * los jugadores pongan sus jugadas sobre la mesa.
	 * El último jugador comprueba si hay o no un ganador, y despierta
	 * al resto de jugadores
	 *  
	 */
	public int nuevaJugada(int id,boolean cara) throws InterruptedException{
		int ganador = N;
		nueva.acquire();
		mutex.acquire();
		moneda[id]=cara;
		numJug++;
		if(cara)numCara++;
		else numCruz++;
		System.out.println("Al jugador "+id+" le ha salido "+cara);
		if(numJug<N){
			mutex.release();
			nueva.release();
			espera.acquire();
			mutex.acquire();
		} else {
			ganador();
		}
		ganador=this.ganador;
		numJug--;
		if(cara)numCara--;
		else numCruz--;
		if(numJug>0)espera.release();
		else{
			nueva.release();
			System.out.println((ganador==N)?"No ha habido ganador":"El ganador ha sido "+ganador);
		}
		mutex.release();
		return ganador;

	}



	private  void ganador(){	
		int gana = -1;
		if (numCara==1) gana = 1;
		if (numCruz==1) gana = 0;
		boolean hayGanador = gana != -1; 
		if (hayGanador){
			boolean enc = false;
			int i = 0;
			while (!enc){
				if ( moneda[i] == (gana == 1)) {
					ganador = i;
					enc = true;
				} else {
					i++;
				}
			}
		} else ganador = N;
	}
}
