public class Data {
    private static int[] M30 = {11, 4, 6, 9};
    private static int FEB = 2;
    private int d;      // Day
    private int m;      // Month
    private int y;      // Year

    private boolean isMonthWith30Days(int m) {
        for (int i = 0; i < M30.length; i++)
            if (M30[i] == m)
                return true;
        return false;
    }
    public Data(int d, int m, int y) throws Exception{
        if ((d >= 1 && d <= 31) && (m >= 1 && m <= 12) && (y >= 1900 && y <= 2023)) {
            if (this.isMonthWith30Days(m)) {
                if (d > 30)
                    throw new Exception("Error: day is not valid for this month");
                this.d = d;
            } else if (m == FEB) {
                if (d > 28)
                    throw new Exception("Error: day is not valid for this month");
                this.d = d;
            } else
                this.d = d;
            this.m = m;
            this.y = y;
        } else
            throw new Exception("Error: invalid data");
    }

    @Override
    public String toString() {
        String s;
        s = (this.d >= 1 && this.d <= 9) ? "0" + this.d + "/" : this.d + "/";
        s += (this.m >= 1 && this.m <= 9) ? "0" + this.m + "/" : this.m + "/";
        s += this.y;
        return s;
    }
    public String toStringAdvanced() {
        String s = this.toString();

        // Correct spelling for day
        switch (this.d) {
            case 1: {
                s += " " + this.d + "st ";
                break;
            }
            case 2: {
                s += " " + this.d + "nd ";
                break;
            }
            case 3: {
                s += " " + this.d + "rd ";
                break;
            }
            default: {
                s += " " + this.d + "th ";
                break;
            }
        }

        // Correct spelling for month
        switch (this.m) {
            case 1: {
                s += "January ";
                break;
            }
            case 2: {
                s += "February ";
                break;
            }
            case 3: {
                s += "March ";
                break;
            }
            case 4: {
                s += "April ";
                break;
            }
            case 5: {
                s += "May ";
                break;
            }
            case 6: {
                s += "June ";
                break;
            }
            case 7: {
                s += "July ";
                break;
            }
            case 8: {
                s += "August ";
                break;
            }
            case 9: {
                s += "September ";
                break;
            }
            case 10: {
                s += "October ";
                break;
            }
            case 11: {
                s += "November ";
                break;
            }
            case 12: {
                s += "December ";
                break;
            }
        }
        s += this.y;
        return s;
    }
}
