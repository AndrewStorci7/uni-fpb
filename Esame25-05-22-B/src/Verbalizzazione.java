public class Verbalizzazione {
    private final Studente studente;
    private final int esito;

    public Verbalizzazione(Studente studente, int esito) {
        this.studente = studente;
        if (esito < 0 || esito > 30) throw new RuntimeException();
        this.esito = esito;
    }

    public Studente getStudente() {
        return studente;
    }

    public int getEsito() {
        return esito;
    }

    // una Verbalizzazione e ’ equals a un ’ altra che abbia stesso esito e stesso studente
    @Override
    public boolean equals(final Object other) {
        if (other instanceof Verbalizzazione)
            return (this.esito == ((Verbalizzazione) other).esito
                    && this.studente.equals(((Verbalizzazione) other).studente));
        else return false;
    }

    public boolean is_inside(final Studente s) {
        return this.studente.equals(s);
    }

    // implementazione del metodo hashCode coerente con equals
    // @Override
    // public int hashCode() { ...}

    @Override
    public String toString() {
        return studente.toString() + "Esito : " + esito + "\n";
    }
}
