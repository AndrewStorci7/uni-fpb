package classes.exc;

public class DenEqualsToZeroException extends RuntimeException {
    public DenEqualsToZeroException() {
        super("denominatore uguale a zero");
    }
}
