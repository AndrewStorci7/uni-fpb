package exceptions;

public class StudenteGiaIscrittoException extends Exception {

    public StudenteGiaIscrittoException(String s) {
        super("Errore: studente " + s + " già iscritto");
    }
}
