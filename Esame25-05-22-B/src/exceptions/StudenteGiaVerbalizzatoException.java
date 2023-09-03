package exceptions;

public class StudenteGiaVerbalizzatoException extends Exception {
    public StudenteGiaVerbalizzatoException(String s) {
        super("Errore: studente " + s + " già verbalizzato");
    }
}
