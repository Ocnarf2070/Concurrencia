package nodo;
import java.util.*;
public class Nodo extends Thread{
	private List<Integer> lista;
	public Nodo(List<Integer> lista){
		this.lista=lista;
	}
	private void a�ade (List<Integer>l,int d,int h){
		for(int i=d;i<h;i++){
			l.add(lista.get(i));
		}
	}
	private void mezcla(List<Integer> l1,List<Integer> l2){
		lista.clear();
		while(l1.size()>0 && l2.size()>0){
			if(l1.get(0)<=l2.get(0)){
				lista.add(l1.get(0));
				l1.remove(0);
			}else{
				lista.add(l2.get(0));
				l2.remove(0);
			}


		}
	}
	public void run(){
		if(lista.size() > 1){
			List<Integer> l1 = new ArrayList<>();
			List<Integer> l2 = new ArrayList<>();
			a�ade(l1, 0, lista.size()/2);
			a�ade(l2, (lista.size()/2)+1, lista.size());
			Nodo n1=new Nodo(l1);
			Nodo n2=new Nodo(l2);
			n1.start();
			n2.start();
			try{
				n1.join();
				n2.join();
			}catch(InterruptedException msg){
				
			}
			mezcla(l1,l2);
		}
	}
}
