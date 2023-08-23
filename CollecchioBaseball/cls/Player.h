//
// Created by andrew-drink on 10/06/23.
//

#ifndef COLLECCHIOBASEBALL_PLAYER_H
#define COLLECCHIOBASEBALL_PLAYER_H

#include <iostream>
using namespace std;

class Player {
private:
    string n;       // name
    string p;       // position
    bool is_gay;
    bool is_the_best;
public:
    Player() {
        n = "Pino";
        p = "Qualsiasi";
        is_gay = true;
        is_the_best = true;
    }
    Player( string n, string p, bool g, bool b ) {
        this->n = n;
        this->p = p;
        this->is_gay = g;
        this->is_the_best = b;
    }

    void isGay() {
        if ( this->is_gay )
            cout << "Si, putroppo " << this->n << " è gay\n";
        else
            cout << "No, per fortuna non è gay (per ora)\n";
    }

    void isTheBest() {
        if ( this->is_the_best && ( this->n == "Pino" || this->n == "pino" || this->n == "PINO" ) )
            cout << "LUI E' IL MIGLIORE DI TUTTI!\n";
        else if ( this->is_the_best )
            cout << "Lui si che è il migliore!\n";
        else
            cout << "Mi dispiace ma non è il migliore, ma l'hai visto ?\n";
    }

    void seePosition() {
        cout << this->n << " gioca nella posizione: " << this->p << endl;
    }
};


#endif //COLLECCHIOBASEBALL_PLAYER_H
