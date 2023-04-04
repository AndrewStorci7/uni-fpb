//
// Created by andrew-drink on 15/03/23.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H
#include "Vector.cpp"

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

void cast_str_fun (string s, Vector* v_a, int& d) {
    if ( s.at(0) == '|' && s.at(1) == '|' ) {
        // TODO: NORMA
        for ( int i = 2; i < s.length(); i++ ) {
            
        }
    } else if ( s.at(0) == '<' ) {
        // TODO: prodotto scalare
    } else if ( s.at(0) == 'p' && s.at(1) == 'r' ) {
        // TODO: proiezione
    }
}

void showMenu(int& d, Vector* v_a) {
    int c_c;
    bool valid;
    string s, c;
    do {
        s = "", c = "";
        valid = false;
        c_c = 0;
        system("clear");
        cout << "------------------------------\n"
             << "\t\tScegli l'operazione:\n"
             << "\t1- Aggiungi un vettore\n"
             << "\t2- Calcola operazione\n"
             << "\t3- Help\n"
             << "\t4- Exit\n"
             << ": ";
        cin >> c;
        if ( stoi( c ) >= 1 && stoi( c ) <= 4 ) {
            c_c = stoi( c );
            switch ( c_c ) {
                case 1: {
                    // Aggiungi un vettore
                    system("clear");
                    string str_to_cast = "", n_v = "";
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

                        valid = false;
                        while (!valid) {
                            cin.clear();
                            cin.ignore(MAX_IGNORE, '\n');
                            cout << "\nInserire il nome del vettore (v, u, w ...): ";
                            getline(cin, n_v);
                            if (n_v.empty()) {
                                cout << "Null character" << endl;
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
                            Vector v = Vector(n, a, n_v);
                            int i = 0;
                            push(v_a, v, d, i);
                        }
                    }
                }
                    break;

                case 2: {
                    /*// Somma fra due vettori
                    chooseFun(v_a, d, valid, 1, s);*/
                    string op = "";
                    while( !valid ) {
                        cout << "Inserisci l'operazione: \n"
                             << "\t- prv(w) \tpr[<name_vector>]([<name_vector>])\n"
                             << "\t- ||v|| \t||[<name_vector>]||\n"
                             << "\t- <v,w> \t<[<name_vector>], [<name_vector>]>\n"
                             << "\t- v +/- w \t[<name_vector>] +/- [<name_vector>]\n"
                             << "\t- cos(v,w) \tcos([<name_vector>], [<name_vector>])\n"
                             << ": ";
                        getline(cin, op);
                        if ( cin.fail() ) {
                            cin.clear();
                            cin.ignore(MAX_IGNORE, '\n');
                        } else if ( op.empty() ) {
                            cin.clear();
                            cin.ignore(MAX_IGNORE, '\n');
                        } else
                            valid = true;
                    }
                    cast_str_fun(op, v_a, d);
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
        }
    } while(c_c < 5);
}

#endif //VECTOR_VECTOR_H
