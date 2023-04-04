import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Razionale {
    private int n;
    private int d;

    // TODO: leggi(), stampa(), somma(), sottrazione(), moltiplicazione(), divisione()

    /**
     * Default constructor
     */
    public Razionale() {
        this.n = 0;
        this.d = 1;
    }

    /**
     * Constructor
     * @param num
     * @param den
     */
    public Razionale( int num, int den ) {
        this.n = num;
        this.d = den;
    }

    /**
     * Copy constructor
     * @param o
     */
    public Razionale( final Razionale o ) {
        this.n = o.n;
        this.d = o.d;
    }

    /**
     * Sum()
     * @param o
     * @return Razionale
     */
    public Razionale somma( final Razionale o ) {
        Razionale r = new Razionale();
        r.d = o.d * this.d;
        r.n = this.n * o.d + this.d * o.n;
        return r;
    }

    /**
     * Add a new Razionale
     * @param i
     */
    public void add( InputStream i ) {
        Scanner sc = new Scanner( i );
        String s = sc.nextLine();
        if ( s.indexOf( '/' ) == -1 )
            throw new RuntimeException( "Carattere separatore errato!" ); // Lancia un eccezione a run-time ( abbastanza generica )
        this.n = Integer.parseInt( s.substring( 0, s.indexOf( '/' ) ) );
        int den = Integer.parseInt( s.substring( s.indexOf( '/' ) + 1) );

        if ( den == 0 )
            throw new RuntimeException( "Denominatore uguale a zero!" );
        else
            this.d = den;
    }

    /**
     * Read()
     * @param p
     */
    public void toString( PrintStream p ) {
        p.println( this.n + '/' + this.d );
    }

    
}
