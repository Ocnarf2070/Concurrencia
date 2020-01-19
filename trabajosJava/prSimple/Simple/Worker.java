package Simple;

import javax.swing.SwingWorker;
import java.util.*;
import java.util.concurrent.ExecutionException;
public class Worker extends SwingWorker<List<Primo>, Void> {

	private Panel panel;
	private int n;
	public Worker(Panel panel,int n){
		this.panel=panel;
		this.n=n;
	}
	private boolean esPrimo(int p) {
		if (p == 1 || p == 2)
			return true;
		else {
			int div = 2;
			boolean esPrimo = true;
			while (esPrimo && div * div <= p) {
				if (p % div == 0)
					esPrimo = false;
				div++;
			}
			return esPrimo;
		}
	}
	@Override
	protected List<Primo> doInBackground() throws Exception {
		List<Primo> lista = new ArrayList<Primo>();
		int p = 0; int primo = 1;
		while (p<n){
			if (esPrimo(primo)){
				lista.add(new Primo(primo, p));
				p++;
			}
			primo++;
		}
	
		return lista;
	}
	public void done(){
		try {
			panel.listaPrimos(get());
		} catch (InterruptedException | ExecutionException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
