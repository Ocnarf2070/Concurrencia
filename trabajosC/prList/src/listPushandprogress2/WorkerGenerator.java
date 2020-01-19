package listPushandprogress2;
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
	private boolean sl1,sl2;
	private Semaphore mutex=new Semaphore(1, true);
	private Semaphore esperar=new Semaphore(1, true);
	private Semaphore producir=new Semaphore(0, true);
	private Semaphore espera1=new Semaphore(0, true);
	private Semaphore espera2=new Semaphore(0, true);
	public WorkerGenerator(Panel panel,int n){
		this.panel=panel;
		this.n=n;
	}
	private void start() throws InterruptedException, ExecutionException{
		//No ponemos aqui la espera de la produccion porque se nos quedaria bloqueado en la primera iteracion
		sl1=false;
		sl2=false;
		mutex.acquire();
		esperar.release();
		ExecutorService servicio= Executors.newCachedThreadPool();
         	numero=new FutureTask<>(new Callable<Double>() {

         		@Override
         		public Double call() throws Exception {
         			return Math.random();
         		}
         		
         	});
         	
         servicio.execute(numero);
         servicio.shutdown();
         buffer=1;
         mutex.release();
         espera1.release();
         espera2.release();
         producir.acquire();//Hemos producido un dato, por lo tanto esperamos a que sea consumido por las sublistas
	}
	private int buffer;
	public Double obtain(int generador) throws InterruptedException, ExecutionException{
		System.out.println("e:"+buffer);
		if(generador==1){
			espera1.acquire();
			buffer-=0.5;
			sl1=true;
		}
		else if(generador==2){
			espera2.acquire();
			buffer-=0.5;
			sl2=true;
		}
		mutex.acquire();
		Double res= numero.get();
		System.out.println("s":buffer);
		if(buffer==0)
		producir.release();
		mutex.release();
		esperar.acquire();
		
		return res; 
		
	}
	@Override
	protected Void doInBackground() throws Exception {
		// TODO Auto-generated method stub
		int i=0;
		double num;
		while(i<n){
			start();
			num=numero.get();
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
