interface Shape {
    void setWidth(double width);
    void setHeight(double height);
    double getArea();
}

class Rectangle implements Shape {
    private double width;
    private double height;

    @Override
    public void setWidth(double width) {
        this.width = width;
    }

    @Override
    public void setHeight(double height) {
        this.height = height;
    }

    @Override
    public double getArea() {
        return width * height;
    }
}

// Square jest teraz niezaleznym obiektem Shape   // ...obiektem implementującym Shape; Ale, mógłby śmiało  dziedziczyc po Rectangle
class Square implements Shape {
    private double side;

    @Override
    public void setWidth(double width) {
        this.side = width;
    }

    @Override
    public void setHeight(double height) {
        this.side = height;
    }

    @Override
    public double getArea() {
        return side * side;
    }
}

public class Lab7_zad3_java {

    public static void main(String[] args) {
        Shape rectangle = new Rectangle();
        rectangle.setWidth(4);
        rectangle.setHeight(5);
        System.out.println("Rectangle area: " + rectangle.getArea());

        Shape square = new Square();
        square.setWidth(4);
        System.out.println("Square area: " + square.getArea());
    }
}
