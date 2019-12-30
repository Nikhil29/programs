import java.applet.*;
import java.awt.*;

/*<applet code="Main" width=1000 height=700></applet>*/
public class Main extends Applet {
    public void paint(Graphics g) {
        g.drawString("Shubham", 200, 300);
        g.drawLine(20, 20, 60, 60);
        g.drawOval(30, 20, 60, 80);
        g.fillOval(150, 120, 190, 160);
        g.drawLine(200, 200, 500, 200);
        g.drawLine(200, 200, 200, 500);
        g.drawLine(500, 500, 500, 200);
        g.drawLine(500, 500, 200, 500);
        // g.drawRect(100,150,200,250);
        int x = 0;
        for (x = 100; x < 400; x += 10)
            g.drawLine(x, 200, x, 500);

        for (x = 200; x < 500; x += 10)
            g.drawLine(100, x, 400, x);
    }
}