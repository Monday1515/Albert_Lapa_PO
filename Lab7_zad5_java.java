interface MessageService {  // poprawnie
    void sendMessage(String message);
}

// implementujemy funkcjonalnosc Email, wykorzystujac interfejs wiadomosci
class EmailService implements MessageService {
    @Override
    public void sendMessage(String message) {
        System.out.println("Sending email: " + message);
    }
}

// implementujemy funkcjonalnosc SMS, wykorzystujac interfejs wiadomosci
class SMSService implements MessageService {
    @Override
    public void sendMessage(String message) {
        System.out.println("Sending SMS: " + message);
    }
}

// konstruktor wykorzystuje interfejs wiadomosci.
// Zatem klasa odpowiedzialna za powiadomienia nie musi byc 
// modyfikowana przy dodawaniu nowych rodzajow wiadomosci (:
class Notification {
    private final MessageService messageService;

    public Notification(MessageService messageService) {
        this.messageService = messageService;
    }

    public void notify(String message) {
        messageService.sendMessage(message);
    }
}

public class Lab7_zad5_java {

    public static void main(String[] args) {

        MessageService emailService = new EmailService();
        Notification emailNotification = new Notification(emailService);
        emailNotification.notify("Welcome to SOLID with Email!");

        MessageService smsService = new SMSService();
        Notification smsNotification = new Notification(smsService);
        smsNotification.notify("Welcome to SOLID with SMS!");
    }
}
