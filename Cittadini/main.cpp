#include "cls/Cittadino/Cittadino.h"
#include "cls/Residente/Residente.h"
#include "cls/Visitatore/Visitatore.h"
#include "cls/Stato/Stato.h"

int main() {
    Stato s = Stato();
    char a[] = "Andrea";
    char b[] = "Storci";
    char e[] = "PR";
    Cittadino* c = new Cittadino( a, b, 20 );
    Visitatore* v = new Visitatore( a, b, 58, Data( 2, 5, 2023 ) );
    Residente* r = new Residente( a, b, 24, e );
    s.add( *c );
    s.add( *v );
    s.add( *r );
    s.print();
    return 0;
}
