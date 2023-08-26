// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
//        Data data = null;
//        while (true) {
//            System.out.println("Inserisci la data (dd/mm/yyyy):");
//            int d = sc.nextInt();
//            int m = sc.nextInt();
//            int y = sc.nextInt();
//            try {
//                data = new Data(d, m, y);
//                break;
//            } catch (Exception e) {
//                System.out.println(e.getMessage());
//            }
//        }
//
//        System.out.println(data.toStringAdvanced());

//        Triangolo t = new Triangolo(5);
//        System.out.println(t.toString());
//
//        int MAX_ARR = 100;
//        int[] A = new int[MAX_ARR];
//        int i = 0, n = 0, max = 0;
//        while (n >= 0) {
//            System.out.println("Inserisci un numero intero positivo " +
//                                "\n(numero minore di 0 per uscire):");
//            n = sc.nextInt();
//            if (n >= 0)
//                A[i] = n;
//            i++;
//        }
//
//        for (int y = 0; y < A.length; y++) {
//            if (A[y] > max)
//                max = A[y];
//        }
//        System.out.println("Il massimo è " + max);

        String s = "";
        System.out.println("Inserisci una stringa: ");
        s = sc.nextLine();
        System.out.println("Stringa inserita: " + s);
        char c = Character.toUpperCase(s.charAt(0));
        String r = c + s.substring(1);
        System.out.println("Stringa modificata: " + r);


//        int x, y, z;
//        System.out.print("Inserisci 3 numeri interi: ");
//        x = sc.nextInt();
//        y = sc.nextInt();
//        z = sc.nextInt();
//        float media = (float) (x + y + z) / 3;
//
//        System.out.println("La media dei 3 numeri inseriti è: " + media);

    }
}