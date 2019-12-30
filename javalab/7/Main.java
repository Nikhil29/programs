import java.util.Scanner;
/*class Sort extends Main
{



}*/

class Main {
	public void quickSort(int[] b, int l, int h) {
		int i = l;
		int j = h;
		int x = b[l];

		if (l < h) {
			while (i < j) {
				while (b[i] < x && i <= h)
					i++;
				while (b[j] > x)
					j--;
				int temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
			quickSort(b, l, j);
			quickSort(b, j + 1, h);
		}
	}

	public static void main(String[] args) {
		int[] a = new int[10];
		Scanner s = new Scanner(System.in);
		System.out.println("Enter 10 numbers to sorted");
		for (int x = 0; x < 10; x++) {
			a[x] = s.nextInt();
		}
		Main o1 = new Main();
		o1.quickSort(a, 0, 9);
		for (int x = 0; x < 10; x++) {
			System.out.println(a[x] + " ");
		}
	}
}