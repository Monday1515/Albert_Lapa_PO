public class lab2_zad2_tablica {

    int tablica[];

    // Konstruktor domyślny
    public lab2_zad2_tablica() {
        tablica = new int[10];
        System.out.println("Utworzono tablice konstruktorem domyślnym.\n");
    }
    
    // Konstruktor z parametrem
    public lab2_zad2_tablica(int size) {
        tablica = new int[size];
        System.out.println("Utworzono tablice wielkosci " + size + " konstruktorem z parametrem.\n");
    }
   
    public static void main(String[] args) {

        // Użycie konstruktora domyślnego
        lab2_zad2_tablica tablica1 = new lab2_zad2_tablica();
      
        // Użycie konstruktora z argumentem
        lab2_zad2_tablica tablica2 = new lab2_zad2_tablica(20);
    }
}