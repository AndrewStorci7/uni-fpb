//
// Created by sandr on 07/06/2023.
//

#ifndef CITTADINI_RESIDENTE_H
#define CITTADINI_RESIDENTE_H

#include "../Cittadino/Cittadino.h"

class Residente : public Cittadino {
private:
    char* cr;   // Comune di residenza
public:
    Residente( char* n, char* c, int e, char* cr ) : Cittadino( n, c, e ) {
        this->cr = cr;
    }

    char* getComuneResidenza() const { return this->cr; }

    void visualizzaDettagli() {
        cout << "Residente {\n"
             << "\t\tNome: " << this->n
             << "\n\t\tCognome: " << this->c
             << "\n\t\tEtà: " << this->e
             << "\n\t\tComune di residenza: " << this->cr << "\n\t}\n";
    }

    bool operator==( Residente& c ) const {
        return ( this->n == c.n && this->c == c.c && this->e == c.e && this->cr == c.cr );
    }
};


#endif //CITTADINI_RESIDENTE_H
