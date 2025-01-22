interface Discount { // poprawnie
      double calculate(double price);
}

class RegularDiscount implements Discount {
    @Override
    public double calculate(double price) {
        return price * 0.90; // 10% rabatu
    }
}

class SeasonalDiscount implements Discount {
    @Override
    public double calculate(double price) {
        return price * 0.80; // 20% rabatu
    }
}

class DiscountApplier {
    public void applyDiscount(Discount discount, double price) {
        System.out.println("Original price: " + price);
        System.out.println("Price after discount: " + discount.calculate(price));
    }
}

public class Lab7_zad2_java {
    public static void main(String[] args) {
        double price = 100.0;

        Discount regularDiscount = new RegularDiscount();
        Discount seasonalDiscount = new SeasonalDiscount();

        DiscountApplier discountApplier = new DiscountApplier();

        System.out.println("Applying regular discount:");
        discountApplier.applyDiscount(regularDiscount, price);

        System.out.println("Applying seasonal discount:");
        discountApplier.applyDiscount(seasonalDiscount, price);
    }
}
