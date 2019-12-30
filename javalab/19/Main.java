class Main {
    public static void main(String[] argv) {
        StringBuffer s = new StringBuffer("Vartika");
        StringBuffer q = new StringBuffer("vardsstikahdssdfdsfsdfsdfsdfsdfsdfdsfsdcghvh");
        System.out.println("using capacity = " + s.capacity());
        System.out.println("using length = " + s.length());
        System.out.println("using reverse = " + s.reverse());
        String b = s.toString();
        System.out.println("using toString = " + b);
        s.reverse();
        String a = "abc111111111111111111111111111111111111111111111";
        System.out.println("using equals = " + s.equals(q));
        s.append(q);
        System.out.println("using append = " + s);
        System.out.println("using capacity = " + s.capacity());
        System.out.println("using length = " + s.length());

    }

}