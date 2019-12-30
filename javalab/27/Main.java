class addi extends Thread implements Runnable {
    int a, b;

    public void set(String a, String b) {
        this.a = Integer.parseInt(a);
        this.b = Integer.parseInt(b);
    }

    public void run() {
        int z = a + b;
        System.out.println("addition of integer = " + z);
    }
}

class addf extends Thread {
    Float a, b;

    public void set(String a, String b) {
        this.a = Float.parseFloat(a);
        this.b = Float.parseFloat(b);
    }

    public void run() {
        Float z = a + b;
        System.out.println("addition of floats = " + z);
    }
}

class Main {
    public static void main(String[] args) {
        addi t1 = new addi();
        addf t2 = new addf();
        t1.set(args[0], args[1]);
        t2.set(args[2], args[3]);
        t1.start();
        t2.start();
    }
}