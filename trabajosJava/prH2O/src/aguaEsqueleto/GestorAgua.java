package aguaEsqueleto;

import java.util.concurrent.locks.*;

public class GestorAgua {
	private Lock l = new ReentrantLock(true);
	private boolean pAbiertaH = true,pAbiertaO=true;
	private Condition cpAbiertaH=l.newCondition();
	private Condition cpAbiertaO=l.newCondition();
	private int nHid=0,nOx=0;
	private Condition esperaMolecula = l.newCondition();
	
	
	public void hListo(int id) throws InterruptedException{ 
		l.lock();
		try{
			while(!pAbiertaH)cpAbiertaH.await();
			nHid++;
			System.out.println("Llega hidrógeno "+id);
			if(nHid==2)pAbiertaH=false;
			if(nHid==2&&nOx==1){
				esperaMolecula.signalAll();
				System.out.println("FUSSSIIIOOOONNN");
			}else{
				esperaMolecula.await();
			}
			
			nHid--;
			System.out.println("Sale hidrógeno "+id);
			if(nHid==0&&nOx==0){
				pAbiertaH=true;
				cpAbiertaH.signalAll();
				pAbiertaO=true;
				cpAbiertaO.signalAll();
				System.out.println("**********************************");
			}
		}finally{
			l.unlock();
		}
		
	}
	
	public void oListo(int id) throws InterruptedException{ 
		l.lock();
		try{
			while(!pAbiertaO)cpAbiertaO.await();
			nOx++;
			System.out.println("Llega oxigeno "+id);
			if(nOx==1)pAbiertaO=false;
			if(nHid==2&&nOx==1){
				esperaMolecula.signalAll();
				System.out.println("FUSSSIIIOOOONNN");
			}else{
				esperaMolecula.await();
			}
			
			nOx--;
			System.out.println("Sale oxigeno "+id);
			if(nHid==0&&nOx==0){
				pAbiertaH=true;
				cpAbiertaH.signalAll();
				pAbiertaO=true;
				cpAbiertaO.signalAll();
				System.out.println("**********************************");
			}
		}finally{
			l.unlock();
		}
	}
}
