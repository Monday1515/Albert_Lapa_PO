public class lab2_zad1_samochod {
  
    String marka;
    String model;
    int rokProdukcji;

    // Konstruktor domyślny
    public lab2_zad1_samochod() {
        marka = "Toyota";
        model = "Corolla";
        rokProdukcji = 2003;
    }
    
    // Konstruktor z argumentami
    public lab2_zad1_samochod(String make, String carModel, int year) {
        marka = make;
        model = carModel;
        rokProdukcji = year;
    }
   
    // Metoda wyświetlająca dane
    public void wyswietlDane() {
        System.out.println("Patrzysz na " + rokProdukcji + " " + marka + " " + model);
    }
   
    public static void main(String[] args) {

        // Utworzenie obiektu z użyciem konstruktora domyślnego
        lab2_zad1_samochod mojSamochod1 = new lab2_zad1_samochod();
       
        // Utworzenie obiektu z użyciem konstruktora z argumentami
        lab2_zad1_samochod mojSamochod2 = new lab2_zad1_samochod("Honda", "Civic", 2008);
        lab2_zad1_samochod mojSamochod3 = new lab2_zad1_samochod("Volkswagen", "Passat", 2021);

        mojSamochod1.wyswietlDane();
        mojSamochod2.wyswietlDane();
        mojSamochod3.wyswietlDane();
    }
}