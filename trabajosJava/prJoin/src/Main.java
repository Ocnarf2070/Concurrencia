import java.util.Arrays;
import java.util.Random;
import prJoin.*;
public class Main {

	public static void main(String[] args) {
int N=15;
Random r= new Random();
int [] a=new int[N];
for(int i=0;i<a.length;i++){
	a[i]=r.nextInt(2);
}
boolean b[]=new boolean[2];
System.out.println(Arrays.toString(a));
esCero b0 = new esCero(a, 0, N/2, 0, b);
esCero b1 = new esCero(a,N/2,N,1,b);
b0.start();
b1.start();
System.out.println(b[0]&&b[1]);
	}

}
