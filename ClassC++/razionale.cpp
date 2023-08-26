//
// Created by andrew-drink on 23/08/23.
//

#include <iostream>
#include <exception>
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
        if (d == 0)
            throw invalid_argument("Error: il denominatore non può essere uguale a 0");
        else
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
    cout << "Inserisci il numero razionale (n/d): ";
    int n, d;
    char sep;
    is >> n >> sep >> d;
    if (sep != '/')
        throw invalid_argument("Error: separatore diverso dal carattere atteso: '/'");
    if (d == 0)
        throw invalid_argument("Error: il denominatore non può essere uguale a 0");
    r = Razionale(n, d);
    return is;
}

ostream& operator<<(ostream& os, const Razionale& r) {
    r.stampa(os);
    return os;
}

int main() {
    Razionale r;
    while (true) {
        try {
            cin >> r;
            break;
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }
    cout << r;
    return 0;
}
