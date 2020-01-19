package Simple;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.util.*;
import java.util.List;
public class Panel extends JPanel{

	JButton si = new JButton("sí");
	JButton no = new JButton("no");
	JLabel primos= new JLabel("primos?");
	JTextField nprimos = new JTextField(5);
	JTextArea area = new JTextArea(10,40);
	JScrollPane scroll = new JScrollPane(area);
	JLabel mensaje = new JLabel("GUI creada");
	
	public Panel(){
		this.setLayout(new BorderLayout());
		JPanel panel = new JPanel();
	
		panel.add(si);
		panel.add(no);
		panel.add(primos);
		panel.add(nprimos);
	
		this.add(panel,BorderLayout.NORTH);
		this.add(scroll,BorderLayout.CENTER);
		this.add(mensaje,BorderLayout.SOUTH);
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
	
	public void listaPrimos(List<Primo> list){
		for (int i=0; i<list.size(); i++){
			area.append(list.get(i).toString()+" ");
			if ((i+1)%10==0) area.append("\n");
		}
		area.append("\n");
	}
	
	public void limpiarArea(){
		area.setText("");
	}
	
	public int numero(){
		return Integer.parseInt(nprimos.getText());
	}
}
