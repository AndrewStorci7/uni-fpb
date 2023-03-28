import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int x, y, z;
        System.out.println( "Inserisci 3 numeri interi: " );
        Scanner sc = new Scanner(System.in);

        x = sc.nextInt();
        y = sc.nextInt();
        z = sc.nextInt();
        float m = (float) (x + y+ z) / 3;
        System.out.println( "La media è " + m );
    }
}