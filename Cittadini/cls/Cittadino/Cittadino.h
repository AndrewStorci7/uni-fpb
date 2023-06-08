//
// Created by sandr on 07/06/2023.
//

#ifndef CITTADINI_CITTADINO_H
#define CITTADINI_CITTADINO_H

#include <iostream>
#include <cstring>
using namespace std;

class Cittadino {
protected:
    char n[30];
    char c[30];
    int e;
public:
    Cittadino() {
        strcpy( n, "" );
        strcpy( c, "" );
        e = 0;
    }
    Cittadino( char n[], char c[], int e ) {
        strcpy( this->n, n );
        strcpy( this->c, c );
        this->e = e;
    }

    char* getName() { return this->n; }
    char* getSurname() { return this->c; }
    int getEta() const { return this->e; }

    void visualizzaDettagli() {
        cout << "Cittadino {\n"
             << "\t\tNome: " << this->n
             << "\n\t\tCognome: " << this->c
             << "\n\t\tEtà: " << this->e << "\n\t}\n";
    }

    bool operator==( Cittadino& c ) const {
        return ( this->n == c.n && this->c == c.c && this->e == c.e );
    }
};


#endif //CITTADINI_CITTADINO_H
