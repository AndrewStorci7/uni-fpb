#include "Vector.h"

int main() {
    // Vector v = Vector(4, a);
    // cout << v;
    int def_dim = 10;
    int count = 0;
    Vector* v_arr = new Vector[def_dim];
    showMenu(def_dim, v_arr);

    return 0;
}