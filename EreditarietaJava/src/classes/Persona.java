package classes;

public class Persona {
    protected String n;     // name
    protected String s;     // surname

    public Persona() {
        n = "";
        s = "";
    }
    public Persona(String n, String s) {
        this.n = n;
        this.s = s;
    }
    @Override
    public String toString() {
        return "\n\t\tname: " + this.n +
                "\n\t\tsurname: " + this.s;
    }
}
