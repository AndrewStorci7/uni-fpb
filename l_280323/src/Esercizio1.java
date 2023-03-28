import java.util.Scanner;

public class Esercizio1 {

    public static void main_es1( Scanner s) {
        System.out.println( "Inserire un numero positivo: " );
        int n = s.nextInt();

        char[][] matrix = new char[n][n];

        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++)
                matrix[i][j] = j <= i ? '*' : ' ';
        }

        for ( int i = 0; i < n; i++ )
            System.out.println( matrix[i] );
    }
}
