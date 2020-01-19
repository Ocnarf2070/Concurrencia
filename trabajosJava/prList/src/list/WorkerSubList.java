package list;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutionException;

import javax.swing.SwingWorker;

public class WorkerSubList extends SwingWorker <List<Double>, Void>{
	private List<Double> list;
	private Panel panel;
	private int option;
	public WorkerSubList(Panel panel2, List<Double> list,int option) {
		// TODO Auto-generated constructor stub
		this.panel=panel2;
		this.list=list;
		this.option=option;
	}

	//@Override
	protected List<Double> doInBackground() throws Exception {
		List<Double> lista =new ArrayList<>();
		if(option==0){
			for(int i=0;i<list.size();i++)if(list.get(i)<0.5)lista.add(list.get(i));
		}else{
			for(int i=0;i<list.size();i++)if(list.get(i)>=0.5)lista.add(list.get(i));
		}
		return lista;
	}
	public void done(){
		String opt= (option==0)?"area0":"area1";
		try {
			panel.listaNumero(get(), opt);
		} catch (InterruptedException | ExecutionException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	

}