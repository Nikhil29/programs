import java.util.Scanner;

class stack {
	int st[] = new int[10];
	int top = -1;

	void push(int x) {
		if (this.top >= 10) {
			System.out.println("Stack already full");
		} else {
			this.top += 1;
			st[top] = x;
		}
	}

	void pop() {
		if (top == -1) {
			System.out.println("Stack already empty");
		} else {
			int data = st[top];
			this.top--;
			System.out.println("Stack element " + data + " popped out");
		}
	}

	void print() {
		int x;
		for (x = top; x >= 0; x++) {
			System.out.println(st[x]);
		}
	}
}

class Main {
	public static void main(String[] args) {
		stack o1 = new stack();
		int x, flag = 1;
		do {
			System.out.println("1. Push stack");
			System.out.println("2. Pop stack");
			System.out.println("3. Print stack");
			System.out.println("4. exit");
			System.out.println("Enter operation number ");
			Scanner s = new Scanner(System.in);
			s.nextInt();
			switch (x) {
			case 1: {
				int data;
				System.out.println("Enter element ");
				Scanner s1 = new Scanner(System.in);
				s1.nextInt();
				o1.push(data);
				break;
			}
			case 2: {
				o1.pop();
				break;
			}
			case 3: {
				o1.print();
				break;
			}
			case 4: {
				flag = 0;
				break;
			}
			}
		} while (flag != 0);
	}
}