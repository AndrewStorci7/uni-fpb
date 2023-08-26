//
// Created by sandr_ft5c0vu on 26/08/2023.
//

#ifndef EREDITARIETÀ_QUADRATO_H
#define EREDITARIETÀ_QUADRATO_H

#include "Persona.h"

class Studente : public Persona {
private:
    int matricola;
    string uni;
    string email;
public:
    Studente() : Persona() {
        matricola = 0;
        uni = "";
        email = "";
    }

    Studente(string n, string s, int m, string u) : Persona(n, s) {
        this->matricola = m;
        this->uni = u;
        this->email = n + s + "@studenti.unipr.it";
    }

    void print(ostream& os) const {
        cout << "\nStudente " << this->name << " " << this->surname << " {"
                "\n\tmatricola: " << this->matricola <<
                "\n\tuniversità: " << this->uni <<
                "\n\temail: " << this->email <<
                "\n}\n";
    }
};

ostream& operator<<(ostream& os, const Studente& s) {
    s.print(os);
    return os;
}



#endif //EREDITARIETÀ_QUADRATO_H
