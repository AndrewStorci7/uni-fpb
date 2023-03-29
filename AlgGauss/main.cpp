#include "classes/Razionale.cpp"

int main() {
    Razionale r = Razionale( -6, 6 );
    Razionale o = Razionale( -9, 5 );
    Razionale res = r - o;
    Razionale prova;
    cin >> prova;
    cout << prova;
    cout << res;
    return 0;
}
