interface I1 {
    public void f1();
}

interface I2 {
    public void f2();
}

interface I3 {
    public void f3();
}

interface I4 {
    public void f4();
}

class C implements I1, I2, I3, I4 {
    public void f1() {
        System.out.println("from interface 1");
    }

    public void f2() {
        System.out.println("from interface 2");
    }

    public void f3() {
        System.out.println("from interface 3");
    }

    public void f4() {
        System.out.println("from interface 3");
    }
}

class Main {
    public static void main(String[] args) {
        C o1 = new C();
        System.out.println("from class object");
        o1.f1();
        o1.f2();
        o1.f3();
        o1.f4();
        System.out.println("from interface2 object");
        I2 o2 = new C();
        o2.f2();
        System.out.println("from interface2 object");
        I3 o3 = new C();
        o3.f3();
    }
}
