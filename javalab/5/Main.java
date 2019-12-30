class MultiplyMatrix {
	int[][] m = new int[3][3];

	public void multiply(int[][] m1, int[][] m2) {
		for (int x = 0; x < 3; x++)
			for (int k = 0; k < 3; k++)
				for (int y = 0; y < 3; y++) {
					m[x][k] += m1[k][y] + m2[y][k];
				}
	}

	public void display() {
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++)
				System.out.print(m[x][y] + " ");
			System.out.println("");
		}
	}
}

class Main {
	public static void main(String[] args) {
		int[][] m1 = new int[3][3];
		int[][] m2 = new int[3][3];
		int pos = 0;
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {

				m1[x][y] = Integer.parseInt(args[pos++]);
			}
		}

		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 3; y++) {

				m2[x][y] = Integer.parseInt(args[pos++]);
			}
		}
		MultiplyMatrix o1 = new MultiplyMatrix();
		o1.multiply(m1, m2);
		o1.display();
	}
}
