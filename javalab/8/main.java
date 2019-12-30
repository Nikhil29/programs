import java.util.*; //util.list;
import javax.swing.JOptionPane;

class Main {
    public static void main(String[] args) {
        Set l1 = new TreeSet();
        System.out.println("enter data for tree Set");
        String f = "";
        String data;
        do {
            data = JOptionPane.showInputDialog("Enter the element ");
            l1.add(data);
            f = JOptionPane.showInputDialog("Want to enter more ?(y/n)");
        } while (f.equalsIgnoreCase("y"));
        System.out.println("done with adding..now displaying data");
        for (Iterator i = l1.iterator(); i.hasNext();) {
            String a = (String) i.next();
            System.out.println(a);
        }
    }
}