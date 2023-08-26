//
// Created by sandr_ft5c0vu on 26/08/2023.
//

#ifndef EREDITARIETÀ_DOCENTE_H
#define EREDITARIETÀ_DOCENTE_H

#include "Persona.h"

class Docente : public Persona {
private:
    string insegnamento;
    string email;
public:
    Docente() : Persona() {
        insegnamento = "";
        email = "";
    }

    Docente(string n, string s, string i) : Persona(n, s) {
        this->insegnamento = i;
        this->email = n + s + "@docenti.unipr.it";
    }

    void print(ostream& os) const {
        os << "\nDocente " << this->name << " " << this->surname << " {"
             "\n\tinsegnamento: " << this->insegnamento <<
             "\n\temail: " << this->email <<
             "\n}\n";
    }
};

ostream& operator<<(ostream& os, const Docente& d) {
    d.print(os);
    return os;
}

#endif //EREDITARIETÀ_DOCENTE_H
