package classes;

public class Couple <T extends Comparable<Object>> {
    private final T first;
    private final T second;

    public Couple(T f, T s) {
        if (f == null & s == null)
            throw new NullPointerException();
        this.first = f;
        this.second = s;
    }

    public final T getFirst() { return this.first; }
    public final T getSecond() { return this.second; }

    public final T greatest() {
        if (this.first.compareTo(this.second) > 0)
            return first;
        else if (this.first.compareTo(this.second) == 0) {
            if (this.first instanceof Razionale) {
                Razionale copyF = (Razionale) this.first;
                Razionale copyS = (Razionale) this.second;
                return (T) copyF.mul(copyS);
            }
        }
        return this.second;
    }

    @Override
    public String toString() {
        return "\nCouple {\n\t" +
                this.first.toString() + "\n\t" +
                this.second.toString() + "\n}\n";
    }
}
