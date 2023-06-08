//
// Created by sandr on 07/06/2023.
//

#ifndef CITTADINI_DATA_H
#define CITTADINI_DATA_H

#include "../Cittadino/Cittadino.h"

class Data {
private:
    int g;
    int m;
    int a;
public:
    Data() {
        this->g = 1;
        this->m = 1;
        this->a = 1999;
    }
    Data( int g, int m, int a ) {
        this->g = g;
        this->m = m;
        this->a = a;
    }

    int getDay() const { return this->g; }
    int getMonth() const { return this->m; }
    int getyear() const { return this->a; }


    bool operator==( Data& c ) const {
        return ( this->g == c.g && this->m == c.m && this->a == c.a );
    }
};

inline ostream& operator<<( ostream& de, const Data& d ) {
    return de << d.getDay() << "/" << d.getMonth() << "/" << d.getyear();
}

#endif //CITTADINI_DATA_H
