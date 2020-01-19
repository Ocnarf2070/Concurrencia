package prControl2013;

import java.util.*;
import java.util.concurrent.locks.*;
public class Tienda {
	private static Lock l=new ReentrantLock(true);
	private static Condition esperaDescarado=l.newCondition();
	private static Condition esperaAmable=l.newCondition();
	private static Condition esperaDependiente=l.newCondition();
	private static int nDesc=0,nAma=0,total=0;
	private static boolean ocupado=false;

	private static Random r = new Random();

	/** llamado por el cliente id amable cuando quiere su raci�n de
	 *   queso. Cuando el m�todo termina, el cliente tiene que tener
	 *   su raci�n
	 * @throws InterruptedException 
	 */
	private static void qQuesoAmable(int id) throws InterruptedException {
		l.lock();
		
		try{
			nAma++;
			esperaDependiente.signal();
			if(ocupado)esperaAmable.await();
			ocupado=false;
			System.out.println("Cliente amable "+id+" atendido");
		}finally{
			l.unlock();
		}
	}
	/** llamado por el cliente id descarado cuando quiere su raci�n de
	 *   queso. Cuando el m�todo termina, el cliente tiene que tener
	 *   su raci�n
	 * @throws InterruptedException 
	 */

	private static void qQuesoDescarado(int id) throws InterruptedException{
		l.lock();
		try{
			nDesc++;
			esperaDependiente.signal();
			if(ocupado)esperaDescarado.await();
			ocupado=true;
			System.out.println("Cliente descarado "+id+" atendido");

		}finally{
			l.unlock();
		}
	}
	/** llamado por el dependiente para atender a un cliente.  Si hay 	*   clientes debe atender primero a los descarados y luego a los 		*   amables. Si no hay clientes, debe esperar dormido.
	 * @throws InterruptedException 
	 */

	private static void siguiente() throws InterruptedException{
		l.lock();
		try{
			ocupado=false;
			if(nDesc+nAma==0){
				System.out.println("Dependiemte duerme");
				//if(total==20)System.exit(10);
				esperaDependiente.await();
				
			}
			total++;
			if(nDesc!=0){
				System.out.println("Dependiente Cliente descarado atendido "+total);
				nDesc--;
				esperaDescarado.signal();
			}else{
				System.out.println("Dependiente Cliente amable atendido "+total);
				nAma--;
				esperaAmable.signal();
			}
		}finally{
			l.unlock();
		}
	}

	public static class ClienteAmable extends Thread{
		private int id;
		public ClienteAmable(int id){
			this.id = id;
		}

		public void run(){

			try {
				Thread.sleep(r.nextInt(2000));
				qQuesoAmable(id);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}
	}

	public static class ClienteDescarado extends Thread{
		private int id;
		public ClienteDescarado(int id){
			this.id = id;
		}

		public void run(){

			try {
				Thread.sleep(r.nextInt(2000));
				qQuesoDescarado(id);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}

	}

	public static class Dependiente extends Thread{
		public void run(){
			while (true)
				try {
					siguiente();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

		}
	}

	public static void main(String[] args) throws InterruptedException{
		Dependiente d = new Dependiente();
		d.start();
		int dia=0;
		do{
			System.out.println("Dia "+dia);
		ClienteDescarado[] cd = new ClienteDescarado[10];
		ClienteAmable[] ca = new ClienteAmable[10];
		for (int i = 0; i<cd.length; i++){
			cd[i] = new ClienteDescarado(i);
		}
		for (int i = 0; i<ca.length; i++){
			ca[i] = new ClienteAmable(i);
		}
		
		for (int i = 0; i<cd.length; i++){
			cd[i].start();
		}
		for (int i = 0; i<ca.length; i++){
			ca[i].start();
		}
		dia++;
		Thread.sleep(5000);
		}while(true);
		
	}

}
