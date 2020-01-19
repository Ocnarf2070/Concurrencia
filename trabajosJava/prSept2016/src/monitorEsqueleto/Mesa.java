package monitorEsqueleto;

import java.util.Scanner;
import java.util.concurrent.locks.*;
public class Mesa {
	private int numJug=0,N,ganador=N,numCara=0,numCruz=0;
	private boolean [] moneda;
	private Lock l = new ReentrantLock(true);
	private Condition espera=l.newCondition();
	
	/**
	* N es el número de jugadores que intervienen
	*/
	public Mesa(int N){
		this.N=N;
		moneda=new boolean [N];
	}
	/**
	*
	* @param id del jugador que llama al método
	* @param cara : true si la moneda es cara, false en otro caso
	* @return un valor entre 0 y N. Si devuelve N es que ningún jugador
	* ha ganado y hay que repetir la partida. Si devuelve un número
	* menor que N, es el id del jugador ganador.
	*
	* Un jugador llama al método nuevaJugada cuando quiere poner
	* el resultado de su tirada (cara o cruz) sobre la mesa.
	* El jugador deja su resultado y, si no es el último, espera a que el
	* resto de los jugadores pongan sus jugadas sobre la mesa.
	* El último jugador comprueba si hay o no un ganador, y despierta
	* al resto de jugadores
	 * @throws InterruptedException 
	*
	*/
	public int nuevaJugada(int id,boolean cara) throws InterruptedException {
		int ganador = N;
		l.lock();
		try{
			moneda[id]=cara;
			numJug++;
			if(cara)numCara++;
			else numCruz++;
			System.out.println("Al jugador "+id+" le ha salido "+cara);
			if(numJug<N)espera.await();
			else{
				ganador();
			}
			ganador=this.ganador;
			numJug--;
			if(cara)numCara--;
			else numCruz--;
			if(numJug==N-1){
				System.out.println((ganador==N)?"No ha habido ganador":"El ganador ha sido "+ganador);
				espera.signalAll();
			}
		}finally{
			/*Scanner sc= new Scanner(System.in);
			sc.next();*/
			
			l.unlock();
		}
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
