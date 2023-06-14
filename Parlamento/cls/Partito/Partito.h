//
// Created by sandr on 08/06/2023.
//

#ifndef PARLAMENTO_PARTITO_H
#define PARLAMENTO_PARTITO_H


class Partito {
protected:
    char nome[50];
    char sigla[5];
    char p[60];
public:
    Partito( char n[], char s[], char p[] ) {
        this->nome = n;
        this->sigla = s;
        this->p = p;
    }

    
};


#endif //PARLAMENTO_PARTITO_H
