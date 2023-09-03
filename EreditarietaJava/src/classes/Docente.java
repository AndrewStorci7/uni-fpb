package classes;

public class Docente extends Persona {
    private String i;       // insegnamento

    public Docente() {
        super();
        i = "";
    }
    public Docente(String n, String s, String i) {
        super(n, s);
        this.i = i;
    }

    @Override
    public String toString() {
        return "Docente " + this.n + " " + this.s + " {" +
                super.toString() +
                "\n\t\tinsegnamento: " + this.i +
                "\n\t}\n";
    }
}
