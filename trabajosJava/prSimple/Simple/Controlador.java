package Simple;
import java.awt.event.*;
import java.util.*;
public class Controlador implements ActionListener{

	private Panel panel;
	public Controlador(Panel panel){
		this.panel = panel;
	}
	


	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand().equals("SI")){
			panel.mensaje("Sí pulsado");
		} else if (e.getActionCommand().equals("NO")){
			panel.mensaje("No pulsado");
		} else if (e.getActionCommand().equals("PRIMOS")){
			int n = panel.numero();
			try{
				panel.limpiarArea();
				Worker w=new Worker(panel, n);
				w.execute();
			}catch(NumberFormatException ie){
				panel.mensaje("Error: no es un numero");
			}
		}
	}

}
