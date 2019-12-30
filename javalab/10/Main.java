class C1 {
    C1() {
        System.out.println("Constructor of C1");
    }
}

class C2 extends C1 {
    C2() {
        System.out.println("Constructor of C2");
    }
}

class C3 extends C2 {
    C3() {
        System.out.println("Constructor of C3");
    }
}

class C4 extends C3 {
    C4() {
        System.out.println("Constructor of C4");
    }
}

class Main {
    public static void main(String[] args) {
        C4 object = new C4();
    }
}