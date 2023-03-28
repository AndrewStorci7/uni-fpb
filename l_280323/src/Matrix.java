import java.util.Scanner;

public class Matrix {

    public static void main(String[] args) {
        Scanner sc = new Scanner( System.in );
        Esercizio2 e2 = new Esercizio2();
        Esercizio1 e1 = new Esercizio1();
        int choose = 0;
        System.out.println( "Scegli l'esercizio: \n" +
                            "\t 1- Matrice triangolo\n" +
                            "\t 2- Trova il numeor maggiore in un array\n" +
                            ": ");
        choose = sc.nextInt();
        switch ( choose ) {
            case 1:
                System.out.println( "ESERCIZIO 1: " );
                e1.main_es1( sc );
                break;
            case 2:
                System.out.println( "ESERCIZIO 2: " );
                e2.main_es2( sc );
                break;
        }


        sc.close();
    }
}
