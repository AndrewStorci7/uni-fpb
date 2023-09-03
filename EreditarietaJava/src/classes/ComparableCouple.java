package classes;

public class ComparableCouple<D extends Comparable<D>>
        extends Couple
        implements Comparable<ComparableCouple<D>> {

    public ComparableCouple(D f, D s) {
        super(f, s);
    }

    @Override
    public int compareTo(ComparableCouple<D> d) {
        if (this.getFirst().compareTo(d.getFirst()) == 0)
            return this.getSecond().compareTo(d.getSecond());
        return this.getFirst().compareTo(d.getFirst());
    }
}
