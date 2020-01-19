import FilosofoMon.*;
public class PrincipalMon {
	private static final int FILOSOFOS=5;
	public static void main(String[] args) {
		Silla sillas=new Silla();
		Tenedor[] ten = new Tenedor [5];
		for(int i=0;i<ten.length;i++)ten[i]=new Tenedor(i);

		Filosofo[] f=new Filosofo[FILOSOFOS];
		for(int i=0;i<f.length;i++)f[i]=new Filosofo(i, ten[i], ten[(i+5)%5],sillas);

		for(int i=0;i<f.length;i++)f[i].start();
	}

}

