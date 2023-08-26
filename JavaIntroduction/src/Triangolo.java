public class Triangolo {
    private char[][] M;

    public Triangolo(int n) {
        this.M = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int y = 0; y < i + 1; y++)
                this.M[i][y] = '*';
        }
    }

    @Override
    public String toString() {
        String s = "";
        for (int i = 0; i < this.M.length; i++) {
            for (int y = 0; y < this.M[i].length; y++)
                s += this.M[i][y] + " ";
            s += "\n";
        }
        return s;
    }
}
