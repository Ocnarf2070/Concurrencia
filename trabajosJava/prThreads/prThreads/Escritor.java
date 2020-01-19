package prThreads;

public class Escritor extends Thread {
	private int id;
	private char c;
	public Escritor(int num,char let){
		id=num;
		c=let;
	}
	public void run(){
		System.out.println("soy "+id);
		for(int i=0;i<1000;i++){
			System.out.print(c);
			Thread.yield();
			if(i%10==0)System.out.println();
			/*try {
				//Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}*/
		}
	}
}
