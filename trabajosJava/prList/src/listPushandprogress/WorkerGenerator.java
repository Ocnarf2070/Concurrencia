package listPushandprogress;
import java.util.List;
import java.util.concurrent.Semaphore;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.FutureTask;

import javax.swing.SwingWorker;
public class WorkerGenerator extends SwingWorker<Void, Double> {
	private FutureTask<Double> numero;
	private Panel panel;
	private int n;
	private Semaphore mutex=new Semaphore(1, true);
	private Semaphore producir=new Semaphore(0, true);
	private Semaphore espera1=new Semaphore(0, true);
	private Semaphore espera2=new Semaphore(0, true);
	public WorkerGenerator(Panel panel,int n){
		this.panel=panel;
		this.n=n;
	}
	private void start() throws InterruptedException, ExecutionException{
		//No ponemos aqui la espera de la produccion porque se nos quedaria bloqueado en la primera iteracion
		ExecutorService servicio= Executors.newCachedThreadPool();
         	numero=new FutureTask<>(new Callable<Double>() {

         		@Override
         		public Double call() throws Exception {
         			return Math.random();
         		}
         		
         	});
         	
         servicio.execute(numero);//Creamos el nuevo numero. Utilizamos esta funcion porque podemos coger el valor producido desde cualquier clase.
         servicio.shutdown();
         espera1.release();
         espera2.release();//Ya hemos producido el dato, por lo tanto nohace falta que siga esperando las sublistas a que se produzca el dato
         producir.acquire();
         producir.acquire();//Hemos producido un dato, por lo tanto esperamos a que sea consumido por las sublistas
         //Se hace dos veces, ya que las dos sublistas laman a esta funcion.
         espera1.release();
         espera2.release();//
	}
	public Double obtain(int generador) throws InterruptedException, ExecutionException{
		if(generador==1)espera1.acquire();
		else if(generador==2)espera2.acquire(); // esperamos a que se produzca el dato.
		mutex.acquire();//dato que entra en esclusion mutua
		Double res= numero.get();
		mutex.release();
		if(generador==1||generador==2)producir.release();//Hemos consumido el dato, por lo tanto pedimos mas datos
		//Esto se ejecutara dos veces ya que las sublistas 1 y 2 pasaran por esto, y no se repetira algunas de estas, ya que en las siguientes lineas lo impedira. 
		if(generador==1)espera1.acquire(); //si la sublista1 ya ha cogido un dato, espera a que la otra lo coga
		else if(generador==2)espera2.acquire(); //si la sublista2 ya ha cogido un dato, espera a que la otra lo coga
		return res; 
		
	}
	@Override
	protected Void doInBackground() throws Exception {
		// TODO Auto-generated method stub
		int i=0;
		double num;
		while(i<n){
			start();
			num=obtain(0);
			publish(num);
			this.setProgress((i+1)*100/n);
			//Thread.sleep(1);
			i++;
		}
		return null;
		
	}

	public void process(List<Double> lista){
		panel.listaNumero(lista, "areaLista");
	}
}
