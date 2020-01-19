package simpleProgreso;



import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.util.*;
public class Panel extends JPanel{

	private JButton si = new JButton("sí");
	private JButton no = new JButton("no");
	private JLabel primos= new JLabel("primos?");
	private JTextField nprimos = new JTextField(5);
	private JTextArea area = new JTextArea(10,40);
	private JScrollPane scroll = new JScrollPane(area);
	private JLabel mensaje = new JLabel("GUI creada");
	private JProgressBar  barra = new JProgressBar(0,100);
	
	public Panel(){
		this.setLayout(new BorderLayout());
		JPanel panel = new JPanel();
	
		panel.add(si);
		panel.add(no);
		panel.add(primos);
		panel.add(nprimos);
	
		this.add(panel,BorderLayout.NORTH);
		this.add(scroll,BorderLayout.CENTER);
		JPanel sur = new JPanel();
		sur.add(mensaje);
		sur.add(barra);
		this.add(sur,BorderLayout.SOUTH);
		barra.setValue(0);
		barra.setStringPainted(true);
	}
	
	
	public void controlador(ActionListener ctr){
		si.addActionListener(ctr);
		si.setActionCommand("SI");
		no.addActionListener(ctr);
		no.setActionCommand("NO");
		nprimos.addActionListener(ctr);
		nprimos.setActionCommand("PRIMOS");
	}
	
	public void mensaje(String str){
		mensaje.setText(str);
	}
	
	public void listaPrimos(java.util.List<Primo> lista){
		for (int i=0; i<lista.size(); i++){
			area.append(lista.get(i).toString()+"\n");
		}
	}
	
	public void limpiarArea(){
		area.setText("");
	}
	
	public int numero(){
		return Integer.parseInt(nprimos.getText());
	}
	
	public void progreso(int n){
		barra.setValue(n);
	}
}
