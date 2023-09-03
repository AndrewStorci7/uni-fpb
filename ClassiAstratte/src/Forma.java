public class Forma {
    protected float base;
    protected float altezza;

    public Forma(float base, float altezza) {
        this.base = base;
        this.altezza = altezza;
    }

    public float area() {
        return this.altezza * this.base;
    }
}
