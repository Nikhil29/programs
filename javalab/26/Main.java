class td implements Runnable {
    public void run() {
        System.out.println("Thread Name = " + Thread.currentThread().getName());
        System.out.println("Thread Priority = " + Thread.currentThread().getPriority());
    }
}

class Main {
    public static void main(String[] args) {
        Runnable r = new td();
        Thread t1 = new Thread(r);
        t1.start();
        System.out.println("Thread Status = " + t1.isAlive());
    }
}