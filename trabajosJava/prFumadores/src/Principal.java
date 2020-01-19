import prFumadores.*;
public class Principal {
public static void main(String[] args) {
	Mesa ApetureScience= new Mesa();
	Agente glados=new Agente (ApetureScience);
	Fumador[] fum=new Fumador[3];
	for (int i = 0; i < fum.length; i++) {
		fum[i]=new Fumador(i,ApetureScience);
	}
	for (int i = 0; i < fum.length; i++) {
		fum[i].start();
	}
	
}
}
