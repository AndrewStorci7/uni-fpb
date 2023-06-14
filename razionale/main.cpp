#include <iostream>
using namespace std;

class Razionale {
private:
    int n;
    int d;

    Razionale operation( bool f, const Razionale& o ) const {
        Razionale ret;
        ret.d = ( this->d == o.d ) ? this->d : this->d * o.d;
        ret.n = f ?
                ( (ret.d / this->d) * this->n ) + ( (ret.d / o.d) * o.n ) :
                ( (ret.d / this->d) * this->n ) - ( (ret.d / o.d) * o.n );
        return ret;
    }
public:
    Razionale() {
        n = 0;
        d = 1;
    }

    Razionale( int n, int d ) {
        this->n = n;
        this->d = d;
    }

    Razionale( string s ) {
        for ( int y = 0; y < s.length(); y++ ) {
            if ( s.at(y) == '/' ) {
                this->n = stoi( s.substr(0, y) );
                if ( stoi( s.substr(y + 1) ) != 0 )
                    this->d = stoi( s.substr(y + 1) );
                else
                    throw (string) "Error: Can't initialize a Razionale with den equals to zero";
            }
        }
    }

    int getNum() const { return this->n; }
    int getDen() const { return this->d; }

    Razionale operator+( const Razionale& o ) const {
        return operation( true, o );
    }

    Razionale operator-( const Razionale& o ) const {
        return operation( false, o );
    }

    Razionale operator*( const Razionale& o ) const {
        Razionale ret;
        ret.d = this->d * o.d;
        ret.n = this->n * o.n;
        return ret;
    }

    Razionale operator/( const Razionale& o ) const {
        Razionale ret;
        ret.d = this->d / o.d;
        ret.n = this->n / o.n;
        return ret;
    }
};

ostream& operator<<( ostream& d, const Razionale& r ) {
    return d << r.getNum() << "/" << r.getDen();
}

void operator>>( istream& s, Razionale& r ) {
    cout << "Scrivere il numero in questa maniera: n/d" << endl;
    string _s = "";
    s >> _s;
    if ( _s == "quit" || _s == "exit" || _s == "q" || _s == "e" )
        throw (string) "Quit";
    else
        r = Razionale(_s);
}

int main() {
    Razionale r1;
    Razionale* _a = new Razionale[20]();
    int c = 0;
    do {
        try {
            cin >> r1;
            _a[c] = r1;
            c++;
        } catch( string e ) {
            if ( e == "Quit" )
                return 0;
            cout << e << endl;
        }
    } while( c < 20 );
    return 0;
}
