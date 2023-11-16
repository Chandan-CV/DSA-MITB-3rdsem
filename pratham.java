interface Calculator<T>{
    String add(T a, T b);
    String multiply(T a, T b);
}

class CalculatorImpl implements Calculator<Number>{

    public String add(Number a, Number b) {
        return (a.getClass().toString());
    }

    public String multiply(Number a, Number b) {
        
        return (a.getClass().toString());
    }

    public static void main(String[] args) {
        CalculatorImpl c = new CalculatorImpl();
       System.out.println(c.add(1.0, 2.0));
        System.out.println(c.add(5,8));
    }

}