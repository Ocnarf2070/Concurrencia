package listPushandprogress2;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;

import listPush.WorkerGenerator;

public class Controlador implements ActionListener, PropertyChangeListener{
	private Panel panel;
	public Controlador(Panel panel) {
		this.panel = panel;
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand().equals("LISTA")){
			try{
				int num=panel.numero();
				panel.limpiarAreas();
				panel.progreso(0);
				WorkerGenerator worker = new WorkerGenerator(panel, num);
				worker.addPropertyChangeListener(this);
				worker.execute();
				WorkerSubList worsub0 = new WorkerSubList(panel,worker,num,0);
				worsub0.execute();
				WorkerSubList worsub1=new WorkerSubList(panel,worker,num,1);
				worsub1.execute();
				
			}catch(NumberFormatException ie){
				panel.mensaje("Error: no es un numero");
			}
		}
	}
	public void propertyChange(PropertyChangeEvent evt) {
		if (evt.getPropertyName().equals("progress")){
			panel.progreso((Integer)evt.getNewValue());
		}
		
	}
	/*@Override
	public void propertyChange(PropertyChangeEvent evt) {
		if (evt.getPropertyName().equals("progress")){
			panel.progreso((Integer)evt.getNewValue());
		}
		
	}*/

}
