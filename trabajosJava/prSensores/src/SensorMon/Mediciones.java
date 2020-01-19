package SensorMon;

public class Mediciones {
	private int n=0;
	private boolean [] nuevaMed={false,false,false};
	public synchronized void nuevaMedicion(int id) throws InterruptedException{
		n++;
		if(n==3)notifyAll();
		System.out.println("Sensor "+id+" deja dato "+n);
		while(!nuevaMed[id])
		wait();
		nuevaMed[id]=false;
	}
	public synchronized void leerMediciones() throws InterruptedException{
		while(n!=3)wait();
		System.out.println("Trabajor lee "+n+" datos" );
		n=0;
	}
	public synchronized void finTarea(){
		for (int i = 0; i < nuevaMed.length; i++) {
			nuevaMed[i]=true;
		}
		notifyAll();
		System.out.println("Trabajador finaliza tarea");
	}
	
}
