class C1 {
    C1() {
        System.out.println("Constructor of C1");
    }

    C1(int a, int b) {
        System.out.println("Paramentrised Constructor of C1");
    }
}

class C2 extends C1 {
    C2() {
        super(1, 2);
        System.out.println("Constructor of C2");
    }

    C2(int a, int b) {
        System.out.println("Paramentrised Constructor of C2");
    }
}

class C3 extends C2 {
    C3() {
        super(1, 2);
        System.out.println("Constructor of C3");
    }

    C3(int a, int b) {
        System.out.println("Paramentrised Constructor of C3");
    }
}

class C4 extends C3 {
    C4() {
        super(1, 2);
        System.out.println("Constructor of C4");
    }

    C4(int a, int b, int c, int d) {
        System.out.println("Parametrised Constructor of C4");
    }
}

class Main {
    public static void main(String[] args) {
        System.out.println("CASE 1");
        C4 object1 = new C4();
        System.out.println("");
        System.out.println("CASE 2");
        C4 object2 = new C4(1, 2, 3, 4);
    }
}