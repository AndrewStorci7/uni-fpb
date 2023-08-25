//
// Created by andrew-drink on 24/08/23.
//

/**
 * Implementare la classe StringSet che realizza il tipo di dato astratto insieme di stringhe
 * • add(x) : aggiunge l’elemento x all’insieme. Se l’elemento è già presente l’insieme rimane inalterato,
 *      nel caso non ci sia spazio sufficiente, il metodo stampa un messaggio d’errore
 * • contains(x) : controlla se x appartiene all’insieme
 * • size() : ritorna la cardinalità dell’insieme
 * • s1 < s2 : verifica se è sottoinsieme di
 * • s1 + s2: ritorna un nuovo insieme ottenuto dall’unione di s1 e s2
 * • Overloading dell’operatore <<
 * • Costruttore vuoto
 * • Costruttore con due parametri, V (array di stringhe) e n (numero di elementi di V)
 */

#include <iostream>
using namespace std;

class StringSet {
private:
    int dim;
    string* container;
public:
    StringSet() {
        dim = 0;
        container = new string[0]();
    }

    StringSet(int d, string* s) : StringSet() {
        for (int i = 0; i < d; i++)
            this->add(s[i]);
    }

    void add(string& s) {
        if (!this->contains(s)) {
            ++dim;
            string* cpy = new string[dim]();
            for (int i = 0; i < dim - 1; i++) {
                cpy[i] = container[i];
            }
            cpy[dim - 1] = s;
            delete[] container;
            container = cpy;
        } else
            cerr << "Error: element/string '" << s << "' already inside the StringSet\n";
    }

    void add(char s[]) {
        if (!this->contains(s)) {
            ++dim;
            string* cpy = new string[dim]();
            for (int i = 0; i < dim - 1; i++) {
                cpy[i] = container[i];
            }
            cpy[dim - 1] = s;
            delete[] container;
            container = cpy;
        } else
            cerr << "Error: element/string '" << s << "' already inside the StringSet\n";
    }

    bool contains(const string& s) const {
        for (int i = 0; i < this->dim; i++) {
            if (s == this->container[i])
                return true;
        }
        return false;
    }

    bool contains(const char s[]) const {
        for (int i = 0; i < this->dim; i++) {
            if (s == this->container[i])
                return true;
        }
        return false;
    }

    void print(ostream& os) const {
        if (dim != 0) {
            os << "StringSet {\n"
                  "\tDimension: " << this->dim;
            for (int i = 0; i < dim; i++)
                os << "\n\tString " << i + 1 << ": " << this->container[i];
            os << "\n}\n";
        } else {
            os << "StringSet {\n"
                  "\tDimension: " << this->dim <<
                  "\n\tEmpty"
                  "\n}\n";
        }
    }

    int size() const { return this->dim; }

    bool operator<(const StringSet& ss) const {
        for (int i = 0; i < this->dim; i++)
            if (!ss.contains(this->container[i]))
                return false;
        return true;
    }

    StringSet& operator=(const StringSet& ss) {
        StringSet ret;
        ret.dim = ss.dim;
        ret.container = new string[ret.dim]();
        for (int i = 0; i < ret.dim; i++)
            ret.container[i] = ss.container[i];
        return ret;
    }

    StringSet operator+(const StringSet& s1) {
        StringSet ret = StringSet(this->dim, this->container);
        for (int i = 0; i < s1.dim; i++)
            ret.add(s1.container[i]);
        return ret;
    }
};

ostream& operator<<(ostream& os, const StringSet& ss) {
    ss.print(os);
    return os;
}

int main() {
    StringSet S1;
    StringSet S2;
    S1.add("Ciao");
    S1.add("ciao");
    S1.add("Andrea");
    S2.add("Andrea");
    cout << S1;
    cout << S2;
    string s = (S2 < S1) ? "True" : "False";
    cout << "The StringSet 'S1' is subset of 'S2' ? " << s << endl;
    StringSet sum = S1 + S2;
    cout << sum;
    return 0;
}