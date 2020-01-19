package Lago;

public class Presa extends Thread{
	private Lago lago;
	private int id;
	public Presa(Lago lago,int id){
		this.id=id;
		this.lago=lago;
	}
}
