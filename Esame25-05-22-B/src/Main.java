public class Main {
    public static void main(String[] args) {
        Studente andrea = new Studente("Andrea", "Storci", 348254);
        Studente marcello = new Studente("Marcello", "Galli", 358675);
        Studente samuel = new Studente("Samuel", "Seligardi", 365872);
        Esame esame = new Esame();
        esame.iscrivi(andrea);
        esame.iscrivi(marcello);
        esame.iscrivi(andrea);
        esame.verbalizza(andrea, 30);
        esame.verbalizza(marcello, 35);
        esame.verbalizza(marcello, 27);
        esame.verbalizza(samuel, 28);
    }
}