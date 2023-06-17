#include <iostream>
using namespace std;

int calcolaMCD(int, int);

class Razionale {
private:
    int n;
    int d;
public:
    void leggi() {
        int d = 0;
        cout << "Inserisci il numeratore: ";
        cin >> this->n;
        cout << "Inserisci il denminatore: ";
        cin >> d;
        if ( d != 0 )
            this->d = d;
        else
            this->d = 1;
    }

    void stampa() {
        cout << this->n << "/" << this->d << endl;
    }

    Razionale somma(Razionale o) {
        Razionale res;
        res.d = this->d * o.d;
        res.n = ((res.d / this->d) * this->n) + ((res.d / o.d) * o.n);
        return res;
    }

    void semplifica() {
        int mcd = calcolaMCD(n , d);
        if ( mcd != 0 ) {
            n /= mcd;
            d /= mcd;
        }
    }

};

int calcolaMCD(int a, int b) {
    // Utilizziamo l'algoritmo di Euclide per calcolare il MCD
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    Razionale r1;
    r1.leggi();
    r1.semplifica();
    r1.stampa();
    return 0;
}
