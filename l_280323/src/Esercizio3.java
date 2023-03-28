import java.util.Scanner;

/**
 * Gioco del TRIS
 */
public class Esercizio3 {

    class Tris {
        private char[][] matrix;
        public Tris() {
            this.matrix = new char[3][3];
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ )
                    matrix[i][j] = '*';
            }
        }

        public void print() {
            for ( int i = 0; i < 3; i++ ) {
                for ( int j = 0; j < 3; j++ )
                    System.out.println( matrix[i][j] + " " );
            }
        }

        public boolean movePlayer( int row, int col, boolean player ) {
            if ( player ) {
                if ( row < 0 || row > 2 || col < 0 || col > 2 )
                    return false;
                if ( matrix[row][col] != '*' )
                    return false;
                matrix[row][col] = 'X';
                return true;
            } else {
                if ( row < 0 || row > 2 || col < 0 || col > 2 )
                    return false;
                if ( matrix[row][col] != '*' )
                    return false;
                matrix[row][col] = 'O';
                return true;
            }
        }

        public int someoneWon() {
            // TODO: Ritornare se uno dei due giocatori ha vinto oppure se è patta
            return 0;
        }

        private boolean playerWon( boolean player ) {
            char c = player ? 'X' : 'O';
            // TODO: Controllare che il giocatore abbia vinto nelle varie posizioni possibili
            return true;
        }

        public boolean isFull() {
            for ( int i = 0; i < 3; i++ )
                for ( int j = 0; j < 3; j++ )
                    if ( matrix[i][j] == '*' )
                        return false;
            return true;
        }
    }
    Scanner sc = new Scanner( System.in );
    Tris game = new Tris();
    boolean player = false; // false GIOCATORE 2 | true GIOCATORE 1
    do {
        int row, col;
        game.print();

        if ( player ) {
            System.out.println( "Giocatore 1: " );
            row = sc.nextInt();
            col = sc.nextInt();
            if ( !game.movePlayer( row, col ) ) {
                System.out.println( "Mossa valida" );
                continue;
            }
        } else {
            System.out.println( "Giocatore 2: " );
            row = sc.nextInt();
            col = sc.nextInt();
            if ( !game.movePlayer( row, col ) ) {
                System.out.println( "Mossa valida" );
                continue;
            }
        }

    } while( !game.someoneWon() && !game.isFull() );
}
