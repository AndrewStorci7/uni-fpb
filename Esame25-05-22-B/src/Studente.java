public class Studente {
    private final String n;
    private final String c;
    private final int m;

    public Studente(String n, String c, int m) {
        this.n = n;
        this.c = c;
        this.m = m;
    }

    @Override
    public String toString() {
        return this.n + " " + this.c + "(" + this.m + ")";
    }

    @Override
    public boolean equals(final Object s) {
        if (s instanceof Studente)
            return (this.m == ((Studente) s).m);
        else return false;
    }

    @Override
    public int hashCode() {
        int ret = 17;
        ret = 31 * ret + n.hashCode();
        ret = 31 * ret + c.hashCode();
        return ret;
    }
}
