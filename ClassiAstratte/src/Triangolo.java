public class Triangolo extends Forma {

    public Triangolo(float base, float altezza) {
        super(base, altezza);
    }

    @Override
    public float area() {
        return super.area() / 2;
    }
}
