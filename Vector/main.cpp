#include <iostream>
#define MAX_IGNORE 1000000000
#define STR_ERR_N "n_different_val"
using namespace std;

class Vector {
private:
    int n;      // R^n
    int* x;     // Array of x, (ex: x1, x2, ..., xn)
public:
    Vector() {
        n = 0;
        x = NULL;
    }

    Vector(int dim, int* arr) : Vector(){
        n = dim;
        x = arr;
    }

    // getter and setter
    void setN(int n) { this->n = n; }
    void setX(int* x) { this->x = x; }
    int getN() { return n; }
    int* getX() { return x; }

    /**
     * @overload of operator <<
     * @param dest
     * @return
     */
    ostream& operator<<(ostream& dest) const {
        dest << "Vector" << this->n << " :";
        for (int i = 0; i < this->n; i++)
            dest << "\t\t" << this->x[i];

        dest << endl;
        return dest;
    }

    /**
     * @overload of operator ==
     * @param Vector
     * @return bool
     */
    bool operator==(const Vector& o) {
        if (this->n != o.n)
            throw (string)STR_ERR_N;

        int c = 0;
        for (int i = 0; i < this->n; i++) {
            if (this->x[i] == o.x[i])
                c++;
        }

        if (c == this->n)
            return true;
        else
            return false;
    }

    /**
     * @overload of operator !=
     * @param Vector
     * @return bool
     */
    bool operator!=(const Vector& o) {
        if (this->n != o.n)
            throw (string)STR_ERR_N;

        int c = 0;
        for (int i = 0; i < this->n; i++) {
            if (this->x[i] != o.x[i])
                c++;
        }

        if (c != 0)
            return true;
        else
            return false;
    }

    Vector operator+(const Vector& o) const {
        if (this->n != o.n)
            throw (string)STR_ERR_N;

        Vector res;
        res.n = o.n;
        int* a = new int[o.n];
        res.x = a;
        for (int i = 0; i < this->n; i++)
            a[i] = this->x[i] + o.x[i];

        return res;
    }

    int operator*(const Vector& o) const {
        if (this->n != o.n)
            throw (string)STR_ERR_N;

        int res = 0;
        for (int i = 0; i < this->n; ++i)
            res += this->x[i] * o.x[i];

        return res;
    }
};



ostream& operator<<(ostream&, const Vector&);
void showMenu(int&, Vector*);
int findTheMaxDim(Vector*, int);
void allargaDimArray(int&, Vector*);
void push(Vector*, Vector, int&, int&);
bool __continue(string);
void printArray(int&, int, Vector*, int);
void chooseFun(Vector*, int, bool, int, string);

int main() {
    // Vector v = Vector(4, a);
    // cout << v;
    int def_dim = 10;
    int count = 0;
    Vector* v_arr = new Vector[def_dim];
    showMenu(def_dim, v_arr);

    return 0;
}

void allargaDimArray(int& dim, Vector* A) {
    Vector* tmp = new Vector[dim * 2];
    for (int i = 0; i < dim; i++)
        tmp[i] = A[i];
    dim *= 2;
    delete [] A;
    A = tmp;
}

void push(Vector* A, Vector v, int& dim, int& i) {
    if (dim != i) {
        if (A[i].getX() == NULL)
            A[i] = v;
        else
            return push(A, v, dim, ++i);
    } else {
        allargaDimArray(dim, A);
        return push(A, v, dim, i);
    }

}

int findTheMaxDim(Vector* A, int dim) {
    int tmp = 0;
    for (int i = 0; i < dim; i++) {
        if (A[i].getN() != 0)
            tmp = (A[i].getN() >= tmp) ? A[i].getN() : tmp;
    }
    return tmp;
}

bool __continue(string s) {
    cin.clear();
    cin.ignore(MAX_IGNORE, '\n');
    cout << "\n\n\npremi invio per tornare al menu ..." << endl;
    getline(cin, s);
    if (s.compare("") == 0)
        return true;
    else
        return false;
}

ostream& operator<<(ostream& dest, const Vector& v) {
    v << dest;
    return dest;
}

void printArray(int& count, int d, Vector* v_a, int n) {
    cout << "  Vettore \t";
    for (int i = 0; i < n; i++)
        cout << "\t\tx" << i + 1;
    cout << endl << "--------------------------------------------" << endl;
    for (int i = 0; i < d; i++) {
        if (v_a[i].getX() != NULL) {
            cout << i + 1 << "- " << v_a[i];
            count++;
        } else
            break;
    }
}

void chooseFun(Vector* v_a, int d, bool valid, int f, string s) {
    int n = findTheMaxDim(v_a, d);
    int a = 0, b = 0, count = 0;
    valid = false;
    system("clear");
    cout << "Scegli due vettori: \n";

    printArray(count, d, v_a, n);

    if(count == 0)
        cout << endl << "Lista vuota!" << endl;

    if(count >= 2) {
        while(!valid) {

            cout << "Inserisci i due indici dei corrispettivi vettori: \n";
            cin >> a;
            cin >> b;
            if (cin.fail()) {
                cout << "Che minghia hai sgritto ffratè ?\n";
                cin.clear();
                cin.ignore(MAX_IGNORE, '\n');
            } else if(a == 0 || b == 0) {
                cout << "Indice non valido!\n";
                cin.clear();
                cin.ignore(MAX_IGNORE, '\n');
            } else if(a > count) {
                cout << "Indice non valido!\n";
                cin.clear();
                cin.ignore(MAX_IGNORE, '\n');
            } else
                valid = true;
        }

        switch (f) {
            case 1: {
                try {
                    system("clear");
                    Vector sum = v_a[a - 1] + v_a[b - 1];
                    cout << "Somma ottenuta: \n";
                    cout << sum;
                } catch (string e) {
                    cout << "Error: " << e << endl;
                }
                bool press_enter = false;
                while(!press_enter) {
                    press_enter = __continue(s);
                }
            }
                break;
            case 2: {
                try {
                    system("clear");
                    int p_s = v_a[a] * v_a[b];
                    cout << "Prodotto scalare: ";
                    cout << p_s;
                } catch (string e) {
                    cout << "Error: " << e << endl;
                }
                bool press_enter = false;
                while(!press_enter) {
                    press_enter = __continue(s);
                }
            }
                break;
        }
    } else
        cout << endl << "Non ci sono abbastanza vettori!" << endl;
}

void showMenu(int& d, Vector* v_a) {
    int c;
    bool valid;
    string s;
    do {
        s = "";
        valid = false;
        c = 0;
        system("clear");
        cout << "------------------------------\n"
             << "\t\tScegli l'operazione:\n"
             << "\t1- Aggiungi un vettore\n"
             << "\t2- Somma fra due vettori\n"
             << "\t3- Prodotto scalare\n"
             << "\t4- Norma di un vettore\n"
             << "\t5- Proiezione"

             << "\t5- Exit\n"
             << ": ";
        cin >> c;
        switch (c) {
            case 1: {
                // Aggiungi un vettore
                system("clear");
                string str_to_cast;
                bool loop = true;
                while (loop) {
                    valid = false;
                    while (!valid) {
                        cin.clear();
                        cin.ignore(MAX_IGNORE, '\n');
                        cout << "\n[Premere enter per tornare al menu ...]" << "\nInserire il numero di variabili: ";
                        getline(cin, str_to_cast);
                        if (str_to_cast.compare("") == 0) {
                            cout << "Enter pressed ..." << endl;
                            loop = false;
                            valid = true;
                            break;
                        } else if (stoi(str_to_cast) == 0) {
                            cin.clear();
                            cin.ignore(MAX_IGNORE, '\n');
                        } else if (cin.fail()) {
                            cin.clear();
                            cin.ignore(MAX_IGNORE, '\n');
                        } else
                            valid = true;
                    }
                    if (loop) {
                        int n = stoi(str_to_cast);
                        int *a = new int[n];
                        for (int i = 0; i < n; i++) {
                            valid = false;
                            while(!valid) {
                                cout << "x" << i + 1 << ": ";
                                cin >> a[i];
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(MAX_IGNORE, '\n');
                                } else
                                    valid = true;
                            }
                        }
                        Vector v = Vector(n, a);
                        int i = 0;
                        push(v_a, v, d, i);
                    }
                }
            }
                break;

            case 2: {
                // Somma fra due vettori
                chooseFun(v_a, d, valid, 1, s);
            }
                break;

            case 3: {
                // prodotto scalare
                chooseFun(v_a, d, valid, 2, s);
            }
                break;

            case 4: {
                // Norma di un vettore
                int n = findTheMaxDim(v_a, d);
                int count = 0;
                int a = 0;
                valid = false;
                system("clear");
                cout << "Scegli un vettore: \n";
                printArray(count, d, v_a, n);


                bool press_enter = false;
                while(!press_enter) {
                    press_enter = __continue(s);
                }
            }
                break;

            case 5:
                cout << "Bye bye ..." << endl;
                c = 6;
                break;
        }
    } while(c < 5);
}