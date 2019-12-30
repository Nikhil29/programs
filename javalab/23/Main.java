import java.awt.*;
import java.awt.event.*;

class frm implements ActionListener {
    Frame f;
    Label l1;
    Label l2;
    Label l3;
    Label l4;
    Label l5;
    Label l6;

    TextField tf1;
    TextField tf2;
    TextField tf3;
    TextField tf4;
    TextField tf5;
    TextField tf6;

    Button b1;
    Button b2;

    public frm() {
        f = new Frame("Registration Form");
        f.setLayout(new GridLayout(7, 2)); /* flow uses awt package */
        l1 = new Label("First Name ");
        tf1 = new TextField(9);
        l2 = new Label("Middle Name ");
        tf2 = new TextField(9);
        l3 = new Label("Last Name ");
        tf3 = new TextField(9);
        l4 = new Label("Address ");
        tf4 = new TextField(9);
        l5 = new Label("Qualification ");
        tf5 = new TextField(9);
        l6 = new Label("DOB ");
        tf6 = new TextField(9);
        b1 = new Button("Submit");
        b2 = new Button("Reset");
        b1.addActionListener(this);
        b2.addActionListener(this);
        f.add(l1);
        f.add(tf1);
        f.add(l2);
        f.add(tf2);
        f.add(l3);
        f.add(tf3);
        f.add(l4);
        f.add(tf4);
        f.add(l5);
        f.add(tf5);
        f.add(l6);
        f.add(tf6);
        f.add(b1);
        f.add(b2);
        f.setSize(500, 500);
        f.setVisible(true);

    }

    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand().equals("Reset")) {
            tf1.setText("");
            tf2.setText("");
            tf3.setText("");
            tf4.setText("");
            tf5.setText("");
            tf6.setText("");
        }
    }
}

class Main {
    public static void main(String[] args) {
        frm ob = new frm();
    }
}