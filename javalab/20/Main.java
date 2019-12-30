class Main {
	public static void main(String[] args) {
		try {
			int a = Integer.parseInt(args[0]);
			int b = Integer.parseInt(args[1]);
			double z = a / b;
			System.out.println(z);
		} catch (ArithmeticException e) {
			System.out.println("Deniminator cannot be zero");
		} catch (NumberFormatException e) {
			System.out.println("not specific data type");
		} catch (ArrayIndexOutOfBoundsException e) {
			System.out.println("no array element available");
		} finally {
			System.out.println("Done finally");
		}

		System.out.println("done all");
	}
}