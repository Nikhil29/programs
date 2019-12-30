class Sum {
    int a, b;

    Sum() {
        a = 0;
        b = 0;
    }

    Sum(int a, int b) {
        this.a = a;
        this.b = b;
    }

    Sum(Sum o) {
        a = o.a;
        b = o.b;
    }

    int add() {
        int sum = a + b;
        return sum;
    }
}

class Main {
    public static void main(String[] args) {
        Sum o1 = new Sum();
        System.out.println("Using default constructor first object, sum = " + o1.add());
        Sum o2 = new Sum(4, 5);
        System.out.println("Using parametrised construtor of second object, sum = " + o2.add());
        Sum o3 = new Sum(o2);
        System.out.println("Using object parametrised construtor of third object, sum = " + o3.add());
    }
}
