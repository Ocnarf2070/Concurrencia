package prFuture;

import java.util.concurrent.ExecutionException;

public class proinciàl{
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PrincipalCallable co=new PrincipalCallable();
		try {
			for (int i = 0; i < 5; i++) {
				co.start();
				System.out.println(co.getNumero());
			}
			
		} catch (InterruptedException | ExecutionException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
