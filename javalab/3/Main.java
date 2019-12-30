class Main {
	public static void main(String args[]) {
		int a = Integer.parseInt(args[0]);
		for (int b = 1; b <= a; b++) {
			int flag = 1;
			for (int c = 2; c < b; c++) {
				if ((b % c) == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				System.out.println(b);
			}
		}
	}
}