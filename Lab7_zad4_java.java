interface Printer {
    void print(String document);
}

interface Scanner {
    void scan(String document);
}

interface Copier {
    void copy(String document);
}

// klasa implementująca wszystkie funkcjonalnosci
class MultiFunctionMachine implements Printer, Scanner, Copier {
    @Override
    public void print(String document) {
        System.out.println("Printing: " + document);
    }

    @Override
    public void scan(String document) {
        System.out.println("Scanning: " + document);
    }

    @Override
    public void copy(String document) {
        System.out.println("Copying: " + document);
    }
}

// Klasa tylko drukujaca
class SimplePrinter implements Printer {
    @Override
    public void print(String document) {
        System.out.println("Printing: " + document);
    }
}

// Klasa tylko skanujaca
class SimpleScanner implements Scanner {
    @Override
    public void scan(String document) {
        System.out.println("Scanning: " + document);
    }
}

public class Lab7_zad4_java {

    public static void main(String[] args) {
        Printer printer = new SimplePrinter();
        printer.print("Document1.pdf");

        Scanner scanner = new SimpleScanner();
        scanner.scan("Document2.pdf");

        MultiFunctionMachine mfm = new MultiFunctionMachine();
        mfm.print("Document3.pdf");
        mfm.scan("Document4.pdf");
        mfm.copy("Document5.pdf");
    }
}