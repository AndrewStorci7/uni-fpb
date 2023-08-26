#include "Studente.cpp"
#include "Docente.cpp"
using namespace std;

int main() {
    Studente s = Studente("Andrea", "Storci", 348264, "Università di Parma");
    Docente d = Docente("Vincenzo", "Arcieri", "Fondamenti di programmazione");
    cout << s;
    cout << d;
    return 0;
}
