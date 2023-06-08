//
// Created by sandr on 07/06/2023.
//

#ifndef CITTADINI_VISITATORE_H
#define CITTADINI_VISITATORE_H

#include "../Data/Data.cpp"
#include "../Cittadino/Cittadino.h"

class Visitatore : public Cittadino {
private:
    Data d = Data();     // Data of arrive
public:
    Visitatore( char* n, char* c, int e, Data d ) : Cittadino( n, c, e ) {
        this->d = d;
    }

    void visualizzaDettagli() {
        cout << "Visitatore {\n"
             << "\t\tNome: " << this->n
             << "\n\t\tCognome: " << this->c
             << "\n\t\tEtà: " << this->e
             << "\n\t\tData di arrivo: " << this->d << "\n\t}\n";
    }

    bool operator==( Visitatore& c ) const {
        return ( this->n == c.n && this->c == c.c && this->e == c.e && this->d == c.d );
    }
};


#endif //CITTADINI_VISITATORE_H
