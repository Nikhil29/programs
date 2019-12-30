class Main {
    public static void main(String[] args) {
        Thread t1 = new Thread();
        t1.setName("JAVA");
        t1.setPriority(Thread.MAX_PRIORITY);
        t1.start();
        System.out.println("Thread Name = " + t1.getName());
        System.out.println("Thread Priority = " + t1.getPriority());
        System.out.println("Thread Status = " + t1.isAlive());
    }
}