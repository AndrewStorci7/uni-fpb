#include <iostream>
using namespace std;

/**
 * SIMLUAZIONE ESAME 25/05/2022 ___ ESRCIZIO 1[C++]: (15 pt.):
 *
 * Definire una classe templatica Inventory che rappresenta un inventario di elementi di tipo T.
 * La classe deve definire un costruttore senza argomenti che crea un inventario vuoto. Il metodo add aggiunge un
 * elemento di tipo T all’inventario. Il metodo count prende come argomento un elemento di tipo T e restituisce il numero
 * di occorrenza dell’elemento passato come argomento. Il metodo getMostCommon restituisce l’elemento che occorre pi`u
 * spesso nell’inventario. Un inventario ha dimensione indefinita. Non `e consentito usare la STL. Se necessario, ridefinire gli
 * opportuni metodi, costruttori e/o operatori.
 *
 * Inventory < int > inv0 ;
 * Inventory < string > inv1 ;
 * inv0 . add (1); inv0 . add (2); inv0 . add (1); inv0 . add (3);
 * inv1 . add ( " hello " ); inv1 . add ( " hello " ); inv1 . add ( " ciao " ); inv1 . add ( " hello " );
 * cout << inv0 . count (7) << endl ; // output : 0
 * cout << inv0 . count (1) << endl ; // output : 2
 * cout << inv1 . count ( " ciao " ) << endl ; // output : 1
 * cout << inv0 . getMostCommon () << endl ; // output : 1
 *
 */



template <typename T>
class Inventory {
private:
    T* A;
    int t;
public:
    Inventory() {
        A = new T[20]();
        t = 0;
    }

    void add( const T& p ) {
        A[this->t] = p;
        this->t++;
    }

    int count( const T& p, int i = 0, int r = 0 ) {
        if ( i == t )
            return r;
        else if ( this->A[i] == p )
            return count( p, i + 1, r + 1 );
        else
            return count( p, i + 1, r );
    }

    T getMostCommon() {
        int m_tmp = 0;
        int i_elem = 0;
        for ( int i = 0; i < this->t; i++ ) {
            int tmp = count( A[i] );
            if ( tmp >= m_tmp ) {
                m_tmp = tmp;
                i_elem = i;
            }
        }
        return A[i_elem];
    }

};

int main() {
    Inventory<int> inv0;
    Inventory<string> inv1;
    inv0.add(1);
    inv0.add(2);
    inv0.add(1);
    inv0.add(3);

    inv1.add("hello");
    inv1.add("hello");
    inv1.add("ciao");
    inv1.add("hello");

    cout << inv0.count(7) << endl;
    cout << inv0.count(1) << endl;
    cout << inv1.count("ciao") << endl;
    cout << inv0.getMostCommon() << endl;
    return 0;
}
