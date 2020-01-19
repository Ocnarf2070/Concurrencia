import java.util.*;

import nodo.Nodo;
public class Principal {
	public static void main(String[] args) {
		Random r=new Random();
		int tam=r.nextInt(20);
		List<Integer>lista=new ArrayList<>();
		for(int i=0; i<tam; i++){
			lista.add(r.nextInt(100));
		}
		System.out.println("Desordenada: \n"+lista);
		Nodo nodo = new Nodo(lista);
		nodo.start();
		try{
			nodo.join();
		}catch (InterruptedException e) {
			// TODO: handle exception
		}
		System.out.println("Ordenada: \n"+lista);
	}

}
