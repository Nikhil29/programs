class addition {
	int a, b, c;

	public void accept(int x, int y) {
		a = x;
		b = y;
	}

	public void add() {
		c = a + b;
	}

	public void display() {
		System.out.println("Sum = " + c);
	}

}

class Main {
	public static void main(String[] args) {
		int x = Integer.parseInt(args[0]);
		int y = Integer.parseInt(args[1]);
		addition o1 = new addition();
		o1.accept(x, y);
		o1.add();
		o1.display();
	}
}
