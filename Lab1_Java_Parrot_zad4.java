// export CPPFLAGS="-I/opt/homebrew/opt/openjdk/include"
import java.util.Scanner; 

public class Lab1_Java_Parrot_zad4 {
    
    String desc = "say";
    int howMany;

    public Lab1_Java_Parrot_zad4 (String newPhrase, int newHowMany) {
        desc = newPhrase;
        howMany = newHowMany;
    }  

    public void say() {
        System.out.println("Parrot will now say '" + desc + "' " + howMany + " times: ");
        for (int i = 0; i < howMany; i++) {
            System.out.println(desc);
        }
    }

    public static void main(String[] args) {
        System.out.println("Hello, World!");

        Scanner whatToSay = new Scanner(System.in);
        System.out.println("What will Parrot say? ");
        String phrase = whatToSay.nextLine();
        System.out.println("How many times should it say it? ");
        int many = whatToSay.nextInt();

        Lab1_Java_Parrot_zad4 parrot = new Lab1_Java_Parrot_zad4(phrase, many);
        parrot.say();
    }
}