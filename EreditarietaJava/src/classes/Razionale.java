package classes;
import java.lang.Cloneable;
import java.util.Scanner;
import classes.exc.*;

import javax.swing.*;

public class Razionale implements Cloneable, Comparable<Object> {
    private int n;
    private int d;

    public Razionale() {
        n = 0;
        d =  1;
    }

    public Razionale(int n, int d) throws DenEqualsToZeroException {
        this.n = n;
        if (d == 0)
            throw new DenEqualsToZeroException();
        this.d = d;
    }

    public Razionale(final Razionale r) {
        this.n = r.n;
        this.d = r.d;
    }

    public void leggi() throws Exception, DenEqualsToZeroException {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int sep = s.indexOf('/'), n = 0, d = 0;
        if (sep == -1)
            n = Integer.parseInt(s.substring(0));
        else {
            n = Integer.parseInt(s.substring(0, sep));
            d = Integer.parseInt(s.substring(sep + 1));
        }

        if (d == 0)
            throw new DenEqualsToZeroException();
        this.n = n;
        this.d = d;
    }

    @Override
    public Razionale clone() throws CloneNotSupportedException {
        return (Razionale) super.clone();
    }
    @Override
    public String toString() {
        return this.n + "/" + this.d;
    }
    @Override
    public boolean equals(final Object r) {
        if (this == r)
            return true;
        else if (r == null)
            return false;
        else if (r instanceof Razionale) {
            Razionale obj = (Razionale) r;
            return (this.n == obj.n && this.d == obj.d);
        } else if (r instanceof Integer)
            return ((this.n % this.d == 0) && (this.n / this.d == (Integer) r));

        return false;
    }

    @Override
    public int compareTo(final Object o) {
        if (o instanceof Razionale) {
            Razionale copy = (Razionale) o;
            if (copy.n == this.n && copy.d == this.d)
                return 0;
            else if ((float)(this.n / this.d) > (float)(copy.n / copy.d) )
                return 1;
            else return -1;
        } else if (o instanceof Integer) {
            Integer i = (Integer) o;
            int check = this.n % this.d;
            if (check == 0) {
                int div = this.n / this.d;
                if (div == i)
                    return 0;
                else if (div > i)
                    return 1;
                else return -1;
            } else {
                float div = this.n / this.d;
                if (div > i)
                    return 1;
                else return -1;
            }
        }
        return -2;
    }

    public final int num() { return this.n; }
    public final int den() { return this.d; }

    public Razionale mul(final Razionale o) {
        return new Razionale((this.n * o.d + o.n * this.d), this.d * o.d);
    }
}
