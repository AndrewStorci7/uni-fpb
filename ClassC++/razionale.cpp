//
// Created by andrew-drink on 23/08/23.
//

#include <iostream>
using namespace std;

class Razionale {
private:
    int n;
    int d;
public:
    Razionale() {
        n = 0;
        d = 1;
    }

    Razionale(int n, int d) {
        this->n = n;
        if (d == 0) {
            cerr << "Denominatore uguale a zero!"
                    "\nDi default verrà messo il valore 1\n";
            this->d = 1;
        } else
            this->d = d;
    }

    Razionale operator+(Razionale o) {
        Razionale ret;
        ret.d = (d == o.d) ? d : d * o.d;
        ret.n = ((ret.d / d) * n) + ((ret.d / o.d) * o.n);
        return ret;
    }

    bool operator>(Razionale o) { return n * o.d > o.n * d; }

    void stampa(ostream& os) const { os << this->n << '/' << this->d << endl; }
};

istream& operator>>(istream& is, Razionale& r) {
    int n, d;
    char sep;
    is >> n >> sep >> d;
    r = Razionale(n, d);
    return is;
}

ostream& operator<<(ostream& os, const Razionale& r) {
    r.stampa(os);
    return os;
}

int main() {
    Razionale r;
    cin >> r;
    cout << r;
    return 0;
}
