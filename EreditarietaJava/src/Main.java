import classes.*;

public class Main {
    public static void main(String[] args) {
        Studente s = new Studente("Andrea", "Storci", 348254);
        Docente d = new Docente("Vincenzo", "Arcieri", "Informatica");
        Razionale r = new Razionale();
        Razionale r2 = new Razionale();
        Razionale clone = new Razionale();

        /**
         * ISTANZA DI RAZIONALE
         */
        do {
            try {
                System.out.println("Inserisci il numero Razionale (n/d):");
                r.leggi();
                System.out.println("Inserisci il numero Razionale (n/d):");
                r2.leggi();
                clone = r.clone();
                System.out.println(r);
                System.out.println(clone);
                System.out.println("I due oggetti di tipo Razionale sono uguali ? " + r.equals(clone));
                break;
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        } while (true);

        /**
         * COUPLE DI RAZIONALE
         */
        do {
            try {
                Couple<Razionale> c = new Couple<Razionale>(r, r2);
                System.out.println(c);
                System.out.println("Compare degli oggetti presenti in Couple: " + c.greatest());
                break;
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        } while (true);

        /**
         * COUPLE DI STUDENTI/DOCENTI
         */
        do {
            try {
                Studente s1 = new Studente("Giacomo", "Leopardi", 102356);
                Studente s2 = new Studente("Gabirele", "Storci", 333654);
                Couple<Studente> c = new Couple<Studente>(s1, s2);
                System.out.println(c);
                System.out.println("Compare degli oggetti presenti in Couple: " + c.greatest());
                break;
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        } while (true);
        System.out.println(s);
        System.out.println(d);
    }
}