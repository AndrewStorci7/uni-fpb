//
// Created by sandr on 07/06/2023.
//

#ifndef CITTADINI_STATO_H
#define CITTADINI_STATO_H

#include "../Cittadino/Cittadino.h"

bool is_inside( Cittadino*, Cittadino& );

class Stato {
private:
    Cittadino* arr = new Cittadino[1]();
    int _tot = 0;
public:
    Stato() {
        arr = new Cittadino[1]();
        _tot = 0;
    }

    void add( Cittadino& c ) {
        if ( is_inside( this->arr, c ) ) {
            cout << "This citizen already exist" << endl;
            throw (int) 1;
        } else if ( _tot == ( sizeof(arr) / sizeof(arr[0]) ) )
            resize_arr_cittadini();

        arr[_tot] = c;
        _tot++;
    }

    void resize_arr_cittadini() {
        int l = ( sizeof(arr) / sizeof(arr[0]) );
        Cittadino* r = new Cittadino[ l * 2 ]();
        for ( int i = 0; i < l; i++ )
            r[i] = arr[i];
        free( arr );
        arr == r;
    }

    void print() {
        cout << "Stato {\n";
        for ( int i = 0; i < _tot; i++ ) {
            cout << "\t";
            arr[i].visualizzaDettagli();
        }
        cout << "\n}\n";
    }
};

inline bool is_inside( Cittadino* c, Cittadino& s ) {
    int l = sizeof(c) / sizeof(c[0]);
    for ( int i = 0; i < l; i++ ) {
        if ( c[i] == s )
            return true;
    }
    return false;
}

#endif //CITTADINI_STATO_H
