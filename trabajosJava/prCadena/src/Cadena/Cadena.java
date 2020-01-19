package Cadena;

import java.util.Arrays;
import java.util.concurrent.Semaphore;

public class Cadena {
	private int [] buffer;
	private int huecos;
	private int[] prod=new int[3];
	private int total = 0;
	private Semaphore mutex=new Semaphore(1, true);
	private Semaphore esperaC=new Semaphore(0,true);
	private Semaphore[] esperaE;
	public Cadena(int N){
		buffer=new int [N];
		for(int i = 0;i<buffer.length;i++)buffer[i]=-1;
		huecos=N;
		for(int i=0;i<3;i++)prod[i]=0;
		for(int i=0;i<3;i++)esperaE[i]=new Semaphore(0,true);
	}
	public void colocar(int tipo) throws InterruptedException{
		mutex.acquire();
		huecos--;
		if(huecos==-1){
			mutex.release();
			esperaC.acquire();
			mutex.acquire();
		}
		int j=0;
		while(buffer[j]!=-1)j++;
		buffer[j]=tipo;
		System.out.println("Colocador deja tipo "+tipo);
		System.out.println(Arrays.toString(buffer));
		prod[tipo]++;
		if(prod[tipo]==0)esperaE[tipo].release();
		
		mutex.release();
	}
	public void extraer(int tipo) throws InterruptedException{
		mutex.acquire();
		prod[tipo]--;
		if(prod[tipo]==-1){
			mutex.release();
			esperaE[tipo].acquire();
			mutex.acquire();
		}
		int j=0;
		while(buffer[j]!=tipo)j++;
		buffer[j]=-1;
		huecos++;
		total++;
		System.out.println("Empaquetador deja tipo "+tipo);
		if(huecos==0)esperaC.release();
		mutex.release();
	}
}
