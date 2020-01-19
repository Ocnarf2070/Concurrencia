package prFuture;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.FutureTask;
 
public class PrincipalCallable {
	private FutureTask<Double> numero;
	private double res=0;
	public double getNumero() throws InterruptedException, ExecutionException{
		return numero.get();
	}
    public void start() {
        try {
            ExecutorService servicio= Executors.newCachedThreadPool();
            	numero=new FutureTask<>(new Callable<Double>() {

            		@Override
            		public Double call() throws Exception {
            			
            			return Math.random();
            		}
            		
            	});
            servicio.execute(numero);
            res+=numero.get();
            System.out.println(numero.get()+" "+res);
            servicio.shutdown();
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (ExecutionException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
         
         
 
    }
 
}