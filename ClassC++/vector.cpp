//
// Created by sandr_ft5c0vu on 26/08/2023.
//

#include <iostream>
#include <exception>
using namespace std;

template <class T>
class Vector {
private:
    int size;
    int capacity;
    T* A;
public:
    Vector() {
        size = 0;
        capacity = 0;
        A = new T[0]();
    }

    Vector(int n) : Vector() {
        if (this->capacity == 0) {
            this->size = 0;
            this->capacity = n;
        } else {
            T* copy = new T[n]();
            for (int i = 0; i < this->capacity; i++) {
                copy[i] = this->A[i];
                this->size++;
            }
            delete[] this->A;
            this->A = copy;
            this->capacity = n;
        }
    }

    Vector(int n, const T& k) : Vector() {
        if (this->capacity != 0) {
            this->size = n;
            this->capacity = n;
            for (int i = 0; i < n; i++)
                this->A[i] = k;
        } else
            throw string("Invalid Instance: the vector was already initialized");
    }

    Vector(const Vector<T>& v) : Vector() {
        this->size = v.size;
        this->capacity = v.capacity;
        this->A = new T[this->capacity]();
        for (int i = 0; i < this->capacity; i++)
            this->A[i] = v.A[i];
    }

    Vector<T> operator=(const Vector<T>& v) {
        Vector<T> ret = Vector<T>(v);
        return ret;
    }

    int getSize() const { return this->size; }
    int getCapacity() const { return this->capacity; }
    bool isEmpty() const { return (this->size == 0); }
    void clear() {
        if (this->size == 0)
            cout << "\nVector already empty\n";
        else {
            for (int i = 0; i < this->capacity; i++)
                this->A[i] = 0;
            this->size = 0;
            cout << "\nVector cleared correctly!\n";
        }
    }

    void resize() {
        T* copy = new T[this->capacity + 15]();
        for (int i = 0; i < this->capacity; i++)
            copy[i] = this->A[i];
        this->capacity += 15;
        delete[] this->A;
        this->A = copy;
    }

    void push_back(T x) {
        if (this->size == this->capacity)
            this->resize();
        this->A[size] = x;
        size++;
    }

    void pop_back() {
        if (this->isEmpty())
            throw string("Error: can't do the pop_back() in a empty vector");
        this->A[this->size - 1] = 0;
        this->size--;
    }

    T operator[](const int& i) {
        if (i >= this->capacity)
            throw invalid_argument("Error: index out of range");
        return this->A[i];
    }
};

int main() {
    Vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(rand() % 30 + 1);
    for (int i = 0; i < v.getSize(); i++)
        cout << v[i] << endl;
    return 0;
}