class Main {
    public static void main(String[] argv) {
        String a[] = { "Shubham", "Kamya", "Vartika", "shubham" };
        System.out.println("Strings in array are");
        int x = 0;
        for (x = 0; x < 4; x++)
            System.out.println(a[x]);
        System.out.println("Length of array of strings = " + a.length);
        System.out.println("Length of an element of array of strings = " + a[1].length());
        System.out.println("Just using concat = " + a[1].concat(a[2]));
        System.out.println("using lower case = " + a[1].toLowerCase());
        System.out.println("using lower case = " + a[2].toUpperCase());
        System.out.println("using equals case = " + a[0].equals(a[3]));
        System.out.println("using equalsIgnoreCase = " + a[0].equalsIgnoreCase(a[3]));
        System.out.println("using compareto = " + a[0].compareTo(a[3]));
        System.out.println("using compareToIgnoreCase = " + a[0].compareToIgnoreCase(a[3]));
        System.out.println("using substring with 1 parameter = " + a[1].substring(2));
        System.out.println("using substring with 2 parameter = " + a[1].substring(1, 3));
        System.out.println("using startswith = " + a[1].startsWith("Ka"));
        System.out.println("using endswith = " + a[1].endsWith("a"));
    }

}