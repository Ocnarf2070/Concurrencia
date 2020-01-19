package Lago;

public class Lago {
	private volatile int nivel=0;
	private volatile boolean fr=false,fp=false,fp1=false,fp0=false;
	private volatile int turnopr=0,turnop=0;
	public void inc(){
		fr=true;
		turnopr=1;
		while(fp && turnopr==1)Thread.yield();
		nivel++;
		System.out.println("incremento: "+nivel);
		fr=false;
		
	}
	public void dec0(){
		fp0=true;
		turnop=1;
		while (fp1 && turnop==1)Thread.yield();
		
		fp=true;
		turnopr=0;
		while(fr &&  turnopr==0)Thread.yield();
		nivel--;
		System.out.println("Decrementa 0: "+nivel);
		fp=false;
		fp0=false;
	}
	public void dec1()
	{
		fp1=true;
		turnop=0;
		while (fp0 && turnop==0)Thread.yield();
		
		fp=true;
		turnopr=0;
		while(fr &&  turnopr==0)Thread.yield();
		nivel--;
		System.out.println("Decrementa 1: "+nivel);
		fp=false;
		fp1=false;
	}
	
}

