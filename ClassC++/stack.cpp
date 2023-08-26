//
// Created by sandr_ft5c0vu on 25/08/2023.
//

#include <iostream>
#include <exception>
using namespace std;

template <class T>
class Stack {
private:
    int dim;
    T* A;
public:
    Stack() {
        dim = 0;
        A = new T[0]();
    }

    ~Stack() {
        delete[] A;
    }

    void resize(bool b) {
        T* cpy;
        if (b) {
            // For Expand/Push
            cpy = new T[++dim]();
            for (int i = 0; i < dim - 1; i++)
                cpy[i] = this->A[i];
        } else {
            // For Decrease/Pop
            cpy = new T[--dim]();
            for (int i = 0; i < dim + 1; i++)
                cpy[i] = this->A[i];
        }
        delete[] A;
        this->A = cpy;
    }

    void push(T d) {
        resize(true);
        this->A[dim - 1] = d;
    }

    void pop() { resize(false); }
    bool empty() const { return (this->dim == 0); }
    int getDim() const { return this->dim; }
    T getIndexA(int i) const { return this->A[i]; }

    void operator=(const Stack<T>& s) {
        if (this != &s) {
            for (int i = 0; i < s.dim; i++)
                this->push(s.A[i]);
        } else
            throw invalid_argument("Error: non è concessa la copia dello stesso oggetto");
    }

    bool operator>(const Stack& s) const { return (this->dim > s.dim); }
    bool operator<(const Stack& s) const { return (this->dim < s.dim); }

    T maxInArray() const {
        T max = 0;
        for (int i = 0; i < this->dim; i++)
            if (this->A[i] > max)
                max = this->A[i];
        return max;
    }
};

template <class T>
ostream& operator<<(ostream& os, const Stack<T>& s) {
    os << "Stack {";
    for (int i = 0; i < s.getDim(); i++)
        os << "\n\t" << i << ": " << s.getIndexA(i);
    os << "\n}\n";
    return os;
}

template <class T>
T Max(const T& f, const T& s) {
    return (f > s) ? f : s;
}

int main() {
    Stack<int> stackInt;
    Stack<int> copy;
    Stack<float> stackFloat;
    Stack<char> stackChar;
    string s;
    s = (stackInt.empty()) ? "True" : "False";
    cout << "stackInt is empty ? " << s << endl;
    stackInt.push(1);
    cout << stackInt;
    stackInt.push(3);
    cout << stackInt;
    stackInt.push(6);
    cout << stackInt;
    stackInt.pop();
    cout << stackInt;
    stackInt.push(-6);
    cout << stackInt;
    s = (stackInt.empty()) ? "True" : "False";
    cout << "stackInt is empty ? " << s << endl;
    copy = stackInt;
    copy.push(4);
    cout << copy;
    cout << stackInt;
    Stack<int> ret = Max(stackInt, copy);
    cout << ret << endl;

    stackFloat.push(2.9);
    stackFloat.push(1.2);
    stackFloat.push(3.6);
    stackFloat.push(7);
    cout << stackFloat << endl;
    cout << stackInt.maxInArray() << endl;
    cout << copy.maxInArray() << endl;
    cout << stackFloat.maxInArray() << endl;
    return 0;
}