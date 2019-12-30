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
    Button b3;
    Button b4;

    public frm() {
        f = new Frame("Calculator");
        f.setLayout(new GridLayout(7, 2)); /* flow uses awt package */
        l1 = new Label("Number 1 ");
        tf1 = new TextField(9);
        l2 = new Label("Number 2 ");
        tf2 = new TextField(9);
        b1 = new Button("Add");
        b2 = new Button("Subtract");
        b3 = new Button("Multiply");
        b4 = new Button("Divide");
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        f.add(l1);
        f.add(tf1);
        f.add(l2);
        f.add(tf2);
        f.add(b1);
        f.add(b2);
        f.add(b3);
        f.add(b4);
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