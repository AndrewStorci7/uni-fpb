//
// Created by sandr_ft5c0vu on 26/08/2023.
//

#ifndef EREDITARIETÀ_PUNTO_H
#define EREDITARIETÀ_PUNTO_H

#include <iostream>
using namespace std;

class Persona {
protected:
    string name;
    string surname;
public:
    Persona() {
        name = "";
        surname = "";
    }

    Persona(string n, string s) : Persona() {
        this->name = n;
        this->surname = s;
    }
};


#endif //EREDITARIETÀ_PUNTO_H
