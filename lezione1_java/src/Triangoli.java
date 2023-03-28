import java.util.Scanner;

public class Triangoli {

    public static void asterischi( int n ) {
        System.out.println( "Fun Asterischi 1" );
        int i = 0, j = 0;
        while ( i < n ) {
            j = 0;
            while ( j < i + 1 ) {
                System.out.print( "* " );
                j++;
            }
            System.out.println( "" );
            i++;
        }
    }

    public static void asterischi2( int n ) {
        System.out.println( "Fun Asterischi 2" );
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < i + 1; j++ )
                System.out.print( "* " );
            System.out.println( "" );
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println( "Inserisci la base del triangolo: " );
        int n = sc.nextInt();
        asterischi(n);
        System.out.println( "----------" );
        asterischi2(n);
    }
}
