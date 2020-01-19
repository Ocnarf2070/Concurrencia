package recursosEsqueleto;

import java.util.concurrent.locks.*;
public class GestorRecursos {
	private Lock l = new ReentrantLock(true);
	private Condition primer=l.newCondition();
	private Condition resto=l.newCondition();
	private int num;
	private int esperando=0;
	
	public GestorRecursos(int num){
		this.num=num;
	}
	
	public void quieroRecursos(int id,int n) throws InterruptedException{
		//el cliente id necesita n recursos
		l.lock();
		try{
			esperando++;
			if(esperando>1)resto.await();
			
			while(num<n)primer.await();
			num-=n;
			System.out.println("Cliente "+id+" toma "+n+" recusos. Quedan "+num);
			
			esperando--;
			resto.signal();
		}finally{
			l.unlock();
		}
		
		
	}

	
	public  void devuelvoRecursos(int id, int n){
		//cliente id devuelve n recursos
		l.lock();
		try{
			num+=n;
			System.out.println("Cliente "+id+" devuelve "+n+" recusos. Quedan "+num);

			primer.signal();
			
		}finally{
			l.unlock();
		}
	
	}
	
	
}
