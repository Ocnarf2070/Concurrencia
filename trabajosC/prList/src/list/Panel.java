package list;

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
		this.add(panelcs,BorderLayout.CENTER);
		this.add(mensaje,BorderLayout.SOUTH);
	}
	public void controlador(ActionListener ctr){
		nLista.addActionListener(ctr);
		nLista.setActionCommand("LISTA");
	}
	public void mensaje(String str) {
		mensaje.setText(str);
	}
	public void listaNumero(List <Double> lista,String comp){
		switch(comp){
		case "areaLista":
			for(int i=0;i<lista.size();i++)	areaList.append("("+i+":"+lista.get(i).toString()+")\n");
			break;
		case "area0":
			for(int j=0;j<lista.size();j++)	area0.append("("+j+":"+lista.get(j).toString()+")\n");
			break;
		case "area1":
			for(int k=0;k<lista.size();k++)	area1.append("("+k+":"+lista.get(k).toString()+")\n");
			break;
		}
		
	}
	public void limpiarAreas(){
		mensaje.setText("");
		areaList.setText("");
		area0.setText("");
		area1.setText("");
	}
	public int numero(){
		return Integer.parseInt(nLista.getText());
	}
}
