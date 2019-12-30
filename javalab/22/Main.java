import java.awt.event.*;
import java.awt.*;

class FrameClass implements ActionListener {
    Frame f;
    Label l1;

    FrameClass() {
        Frame f = new Frame();
        f.setSize(500, 500);
        Button b1 = new Button("OK");
        Button b2 = new Button("Exit");
        Button b3 = new Button("Click");
        Button b4 = new Button("Cancel");

        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);

        l1 = new Label();
        l1.setAlignment(1);
        f.add(b1, BorderLayout.NORTH);
        f.add(b2, BorderLayout.SOUTH);
        f.add(b3, BorderLayout.EAST);
        f.add(b4, BorderLayout.WEST);
        f.add(l1, BorderLayout.CENTER);
        f.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand().equals("Click")) {
            l1.setText("Click");
        }

        if (e.getActionCommand().equals("Cancel")) {
            l1.setText("Cancel");
        }

        if (e.getActionCommand().equals("OK")) {
            l1.setText("OK");
        }

        if (e.getActionCommand().equals("Exit")) {
            l1.setText("Exit");
        }
    }

}

class Main {
    public static void main(String[] args) {
        FrameClass ob = new FrameClass();
    }
}