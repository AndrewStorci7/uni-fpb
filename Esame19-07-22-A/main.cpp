#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Stack {
private:
    T* data;
    int size;
public:
    Stack() {
        size = 0;
        data = new T[0];
    }

    void resize(bool b) {
        int c_size = size;
        if (b)
            size++;
        else {
            size--;
            c_size--;
        }
        T* copy = new T[size];
        for (int i = 0; i < c_size; i++)
            copy[i] = data[i];
        delete[] data;
        data = copy;
    }

    void push(const T& d) {
        resize(true);
        data[size - 1] = d;
    }

    bool is_empty() const {
        return (this->size == 0);
    }

    T pop() {
        if (is_empty())
            throw (string)"Error: Stack vuoto";
        T ret = data[size - 1];
        resize(false);
        return ret;
    }

    void print(ostream& os) const {
        os << "[ ";
        for (int i = 0; i < size; i++) {
            if (i == size - 1)
                os << data[i];
            else
                os << data[i] << ", ";
        }
        os << " ]";
    }
};

template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& s) {
    s.print(os);
    return os;
}

int main() {
    Stack<int> s_int;
    int pop = 0;
    try {
        pop = s_int.pop();
    } catch (string e) {
        cout << e << endl;
    }
    s_int.push(1);
    s_int.push(4);
    s_int.push(3);
    s_int.push(9);
    try {
        pop = s_int.pop();
    } catch (string e) {
        cout << e << endl;
    }
    cout << pop << endl;
    cout << s_int;
    return 0;
}
