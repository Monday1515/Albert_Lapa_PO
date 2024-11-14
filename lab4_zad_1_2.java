public class lab4_zad_1_2 {
  
    private String imie;
    private String nazwisko;
    private int wiek;
    private String email;
    private String telefon;

    // getters
    public String getName() {
        return imie;
    }
    public String getSurname() {
        return nazwisko;
    }
    public int getAge() {
        return wiek;
    }
    public String getEmail() {
        return email;
    }
    public String getNumber() {
        return telefon;
    }

    // setters
    public void setAttrib(String imie, String nazwisko, int wiek) {
        this.imie = imie;
        this.nazwisko = nazwisko;
        this.wiek = wiek;
        System.out.println("Atrybuty przypisano.\n");
    }
    // setters with validation
    public void setEmail(String email) {
        if (email.contains("@") == true) {
            this.email = email;
            System.out.println("Email przypisano.\n");
        } else {
            System.out.println("Email nieprawidlowy!\n");
        }
    }
    public void setNumber(String telefon) {
        if (telefon.length() == 9) {
            this.telefon = telefon;
            System.out.println("Telefon przypisano.\n");
        } else {
            System.out.println("Telefon nieprawidlowy!\n");
        }
    }
   
    public static void main(String[] args) {

        lab4_zad_1_2 przyjaciel1 = new lab4_zad_1_2();
        przyjaciel1.setAttrib("Czarek", "S", 20);
        przyjaciel1.setEmail("csking@op.pl");
        przyjaciel1.setNumber("987654321");
        
        System.out.println(przyjaciel1.getName());
        System.out.println(przyjaciel1.getSurname());
        System.out.println(przyjaciel1.getAge());
        System.out.println(przyjaciel1.getEmail());
        System.out.println(przyjaciel1.getNumber());
    }
}