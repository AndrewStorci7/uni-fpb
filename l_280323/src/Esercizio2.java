/**
 * ESERCZIO 2:
 * Istanziare un array con al più 100 elementi ( che termina con un numero negativo ) e
 * fargli stampare il numero massimo
 */

import java.util.Scanner;
public class Esercizio2 {

    public static int findMax( int[] a, int i, int tmp ) {
        if ( i != a.length ) {
            if ( tmp > a[i] )
                return findMax( a, i + 1, tmp );
            else {
                tmp = a[i];
                return findMax( a, i + 1, tmp );
            }
        } else {
            return tmp;
        }
    }

    public static void main_es2( Scanner s ) {
        int i = 0;
        int[] a = new int[100];
        boolean valid = false;
        while( !valid ) {
            System.out.println( "inserisci un numero positivo intero: " );
            a[i] = s.nextInt();
            if ( a[i] < 0 )
                valid = true;
            else {
                valid = false;
                i++;
            }
        }

        int max = 0;
        if ( valid )
            max = findMax( a, 0, 0 );

        System.out.println( "Massimo trovato: " + max );
    }
}
