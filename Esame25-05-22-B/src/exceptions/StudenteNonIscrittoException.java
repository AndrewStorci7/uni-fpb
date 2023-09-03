package exceptions;

public class StudenteNonIscrittoException extends Exception {

    public StudenteNonIscrittoException(String s) {
        super("Errore: studente " + s + " non iscritto all'esame");
    }
}
