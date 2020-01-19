package listPush;

import java.util.List;
import java.util.concurrent.Semaphore;

import javax.swing.SwingWorker;

public class WorkerSubList extends SwingWorker < Void,Double>{
	private int numero;
	private Panel panel;
	private int option;
	private WorkerGenerator gen;
	public WorkerSubList(Panel panel, WorkerGenerator worker, int num,int option) {
		// TODO Auto-generated constructor stub
		this.panel=panel;
		numero=num;
		this.option=option;
		gen=worker;
	}

	//@Override
	protected Void doInBackground() throws Exception {
		int i=0;
		if(option==0){
			while(i<numero){
				Double res=gen.obtain(1);
				if(res<0.5)publish(res);
				i++;
			}
		}else{
			while(i<numero){
				Double res=gen.obtain(2);
				if(res>=0.5)publish(res);
				i++;
			}
		}
		return null;
	}
	public void process(List<Double> lista){
		String opt= (option==0)?"area0":"area1";
		panel.listaNumero(lista, opt);
	}
	

}