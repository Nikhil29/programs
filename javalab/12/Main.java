interface I1 {
    public void f1();
}

interface I2 extends I1 {
    public void f2();
}

interface I3 extends I2 {
    public void f3();
}

class C implements I3 {
    public void f1() {
        System.out.println("from interface 1");
    }

    public void f2() {
        System.out.println("from interface 2");
    }

    public void f3() {
        System.out.println("from interface 3");
    }
}

class Main {
    public static void main(String[] args) {
        C o1 = new C();
        o1.f1();
        o1.f2();
        o1.f3();
    }
}
