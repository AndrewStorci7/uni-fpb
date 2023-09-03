// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        SocialNetwork facebook = new SocialNetwork("Facebook");
        NormalUser andrea = new NormalUser("Andrea", "Storci");
        NormalUser marcello = new NormalUser("Marcello", "Galli");
        NormalUser daniele = new NormalUser("Daniele", "Pellati");
        PremiumUser vincenzo = new PremiumUser("arciovince");
        PremiumUser maniello = new PremiumUser("manoc++");
        try {
            facebook.addUser(andrea);
            facebook.addUser(maniello);
            facebook.addUser(marcello);
            facebook.addUser(daniele);
            facebook.addUser(vincenzo);
            facebook.addUser(andrea);

        } catch (SocialNetworkException e) {
            System.out.println(e.getMessage());
        }

    }
}