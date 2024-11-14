public class lab4_zad_3 {
  
    protected String stanowisko = "Teacher";
    protected float wynagrodzenie = 28.1f;

    class Administracja extends lab4_zad_3 {
        public float getSalaryAdm() {
            return wynagrodzenie;
        }
        public void pokazDane() {
            System.out.println("Wynagrodzenie: " + wynagrodzenie);
        }
    }
    class Nauczyciel extends lab4_zad_3 {
        public String getPositionThr() {
            return stanowisko;
        }
        public void pokazDane() {
            System.out.println("Pracownik: " + stanowisko);
        }
    }    

    public static void main(String[] args) {

        lab4_zad_3 pracownik = new lab4_zad_3();
        Administracja szefu = pracownik.new Administracja();
        Nauczyciel kamil = pracownik.new Nauczyciel();
        
        szefu.pokazDane();
        kamil.pokazDane();
    }
}