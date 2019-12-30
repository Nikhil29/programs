class count extends Thread {
	public void run() {
		for (int i = 0; i < 5; i++) {
			try {
				Thread.sleep(3000);
			} catch (Exception e) {
				System.out.println(e);
			}
			System.out.println(i);
		}
	}
}

class Main {
	public static void main(String[] args) {
		count t1 = new count();
		count t2 = new count();
		count t3 = new count();
		count t4 = new count();
		t1.start();
		try {
			t1.join();
		} catch (Exception e) {
			System.out.println(e);
		}
		t2.start();
		t3.start();
		t4.start();
	}
}
