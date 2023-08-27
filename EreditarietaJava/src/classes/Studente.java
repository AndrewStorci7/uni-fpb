package classes;

public class Studente extends Persona implements Comparable<Object> {
    private int m;      // matricola
    private String e;   // email

    public Studente() {
        super();
        m = 0;
        e = "";
    }
    public Studente(String n, String s, int m) {
        super(n, s);
        this.m = m;
        this.e = n + s + "@studenti.unipr.it";
    }

    @Override
    public String toString() {
        return "Studente " + this.n + " " + this.s + " {" +
                super.toString() +
                "\n\t\tmatricola: " + this.m +
                "\n\t\temail: " + this.e +
                "\n\t}\n";
    }

    @Override
    public int compareTo(final Object o) {
        if (o instanceof Studente) {
            Studente s = (Studente) o;
            if (this.m == s.m)
                return 0;
            else if (this.m > s.m)
                return 1;
            else return -1;
        }
        return -2;
    }
}
