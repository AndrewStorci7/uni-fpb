//
// Created by sandr on 29/03/2023.
//
#include <iostream>
using namespace std;

const int findChar( string );

class Razionale {
private:
    int n;
    char sep;
    int d;

public:

    /**
     * Default constructor
     */
    Razionale() {
        n   = 0;
        sep = '/';
        d   = 1;
    }

    /**
     * Constructor
     * @param n Numeratore
     * @param d Denominatore
     */
    Razionale( int n, int d ) {
        this->n = n;
        this->d = d;
        sep     = '/';
    }

    /**
     * Constructor with only one parameter
     * @param n Numeratore
     */
    Razionale( int n ) {
        this->n = n;
        this->d = 1;
        sep     = '/';
    }

    // getter and setter
    void setN( int n ) { this->n = n; }
    void setD( int d ) { this->d = d; }
    int getN() { return this->n; }
    int getD() { return this->d; }

    Razionale operator+( const Razionale& o ) {
        Razionale r;
        r.d = ( o.d == this->d ) ? o.d : this->d * o.d;
        r.n = ( ( r.d / this->d ) * this->n ) + ( ( r.d / o.d ) * o.n );
        return r;
    }

    Razionale operator-( const Razionale& o) {
        Razionale r;
        r.d = ( o.d == this->d ) ? o.d : this->d * o.d;
        r.n = ( ( r.d / this->d ) * this->n ) - ( ( r.d / o.d ) * o.n );
        return r;
    }

    friend ostream& operator<<( ostream& dest, Razionale& o ) {
        dest << o.n << '/' << o.d << endl;
        return dest;
    }

    friend istream& operator>>( istream& serc, Razionale& o ) {
        string s = "", num_s = "", den_s = "";
        int n = 0, d = 0;
        serc >> s;
        int index = findChar( s );
        if ( !s.empty() ) {
            for ( int i = 0; i < s.length(); i++ ) {
                if ( i < index )
                    num_s.append( &s.at(i) );
                else if ( i > index )
                    den_s.append( &s.at(i) );
            }
        }
    }
};

const int findChar( string s ) {
    for ( int i = 0; i < s.length(); i++ )
        if ( s.at(i) == '/')
            return i;
    return 0;
}
/*ostream& operator<<( ostream& dest, Razionale& o ) {
    dest << o.getN() << '/' << o.getN() << endl;
    return dest;
}*/

/*std::ostream& operator>>( std::ostream& dest, Razionale o ) {
    dest << o.getN() << '/' << o.getN() << std::endl;
    return dest;
}*/
