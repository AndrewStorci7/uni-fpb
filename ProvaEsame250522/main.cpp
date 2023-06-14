#include <iostream>
using namespace std;

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
