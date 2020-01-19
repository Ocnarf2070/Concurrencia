package listPushandprogress;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.util.List;

@SuppressWarnings("serial")
public class Panel extends JPanel {
	private static int width=25;
	private static int length = 80;
	private JLabel longLista=new JLabel("Longitud de la lista original?");
	private JTextField nLista=new JTextField(10);
	private JTextArea areaList=new JTextArea(width, length);
	private JScrollPane scroll = new JScrollPane(areaList);
	private JLabel list=new JLabel("Lista original");
	private JTextArea area0=new JTextArea(width, (length-1)/2);
	private JScrollPane scroll2 = new JScrollPane(area0);
	private JTextArea area1=new JTextArea(width,(length-1)/2);
	private JScrollPane scroll3 = new JScrollPane(area1);
	private JLabel text1=new JLabel("Lista de elementos <0.5");
	private JLabel text2=new JLabel("Lista de elementos >=0.5");
	private JLabel mensaje=new JLabel("");
	private JLabel prog=new JLabel("Barra de progreso:");
	private JProgressBar barra= new JProgressBar(0, 100);
	
	public Panel(){
		this.setLayout(new BorderLayout());
		JPanel paneln=new JPanel();
		JPanel panelcs=new JPanel();
		panelcs.setLayout(new GridLayout(2,1));
		paneln.add(longLista);
		paneln.add(nLista);
		
		this.add(paneln,BorderLayout.NORTH);
		JPanel panelc=new JPanel();
		panelc.setLayout(new BorderLayout());
		
		panelc.add(scroll,BorderLayout.CENTER);
		panelc.add(list,BorderLayout.AFTER_LAST_LINE);
		
		panelcs.add(panelc);
		
		JPanel panels=new JPanel();
		JPanel panels1=new JPanel();
		JPanel panels2=new JPanel();
		panels.setLayout(new GridLayout(1,2,10,1));
		panels1.setLayout(new BorderLayout());
		panels2.setLayout(new BorderLayout());
		panels1.add(scroll2,BorderLayout.CENTER);
		panels1.add(text1,BorderLayout.AFTER_LAST_LINE);
		panels2.add(scroll3,BorderLayout.CENTER);
		panels2.add(text2,BorderLayout.AFTER_LAST_LINE);
		panels.add(panels1);
		panels.add(panels2);
		panelcs.add(panels);
		JPanel sur= new JPanel();
		sur.setLayout(new BorderLayout());
		sur.add(mensaje,BorderLayout.SOUTH);
		JPanel progreso=new JPanel();
		progreso.add(prog);
		progreso.add(barra);
		sur.add(progreso,BorderLayout.NORTH);
		this.add(panelcs,BorderLayout.CENTER);
		this.add(sur,BorderLayout.SOUTH);
		barra.setValue(0);
		barra.setStringPainted(true);
		
	}
	public void controlador(ActionListener ctr){
		nLista.addActionListener(ctr);
		nLista.setActionCommand("LISTA");
	}
	public void mensaje(String str) {
		mensaje.setText(str);
	}
	private int i2,j2,k2;
	public void listaNumero(List <Double> lista,String comp){
		switch(comp){
		case "areaLista":
			for(int i=0;i<lista.size();i++){
				areaList.append("("+i2+":"+lista.get(i).toString()+")\n");
				i2++;
			}
			break;
		case "area0":
			for(int j=0;j<lista.size();j++){
				area0.append("("+j2+":"+lista.get(j).toString()+")\n");
				j2++;
			}
			break;
		case "area1":
			for(int k=0;k<lista.size();k++){
				area1.append("("+k2+":"+lista.get(k).toString()+")\n");
				k2++;
			}
			break;
		}
		System.out.println("total: "+i2+" suma: "+(j2+k2));
		
	}
	public void limpiarAreas(){
		mensaje.setText("");
		areaList.setText("");
		area0.setText("");
		area1.setText("");
		i2=0;j2=0;k2=0;
	}
	public int numero(){
		return Integer.parseInt(nLista.getText());
	}
	public void progreso(int n){
		barra.setValue(n);
	}
}