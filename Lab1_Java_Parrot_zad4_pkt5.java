// export CPPFLAGS="-I/opt/homebrew/opt/openjdk/include"
import java.util.*; 

public class Lab1_Java_Parrot_zad4_pkt5 {

    Vector<String> newWords;

    public Lab1_Java_Parrot_zad4_pkt5 (Vector<String> wordsLearned) {
        newWords = wordsLearned;
    }  

    public void say() {
        newWords.remove(newWords.size() - 1);
        int randomNum = (int)(Math.random() * (newWords.size() + 1));
        System.out.println("Your parrot says '" + newWords.get(randomNum) + "'");
    }

    public static void main(String[] args) {
        System.out.println("Hello, World!");
        
        Vector<String> words = new Vector<String>();
        Scanner whatToSay = new Scanner(System.in);
        System.out.println("Teach your parrot some new words. When you are done, say 'stop'.");
        String phrase = "tmp";
        while (phrase.equals("stop") == false) {
            phrase = whatToSay.nextLine();
            words.addElement(phrase);
            // System.out.println(words);
        }
        Lab1_Java_Parrot_zad4_pkt5 parrot = new Lab1_Java_Parrot_zad4_pkt5(words);
        parrot.say();
    }
}