//
// Created by andrew-drink on 15/03/23.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

class Vector {
private:
    int n;      // R^n
    int* x;     // Array of x, (ex: x1, x2, ..., xn)
public:
    Vector() {
        n = 0;
        x = NULL;
    }

    Vector(int dim, int* arr) : Vector(){
        n = dim;
        x = arr;
    }

    // getter and setter
    void setN(int n) { this->n = n; }
    void setX(int* x) { this->x = x; }
    int getN() { return n; }
    int* getX() { return x; }

    Vector sommaVettori(const Vector& o, int& i) {

    }

    /**
     * @overload of operator <<
     * @param dest
     * @return
     */
    ostream& operator<<(ostream& dest) const {
        dest << "Vector" << this->n << " :";
        for (int i = 0; i < this->n; i++)
            dest << "\t\t" << this->x[i];

        dest << endl;
        return dest;
    }

    /**
     * @overload of operator ==
     * @param Vector
     * @return bool
     */
    bool operator==(const Vector& o) {
        if (this->n != o.n)
            throw (string)STR_ERR_N;

        int c = 0;
        for (int i = 0; i < this->n; i++) {
            if (this->x[i] == o.x[i])
                c++;
        }

        if (c == this->n)
            return true;
        else
            return false;
    }

    /**
     * @overload of operator !=
     * @param Vector
     * @return bool
     */
    bool operator!=(const Vector& o) {
        if (this->n != o.n)
            throw (string)STR_ERR_N;

        int c = 0;
        for (int i = 0; i < this->n; i++) {
            if (this->x[i] != o.x[i])
                c++;
        }

        if (c != 0)
            return true;
        else
            return false;
    }

    Vector operator+(const Vector& o) const {
        if (this->n != o.n)
            throw (string)STR_ERR_N;

        Vector res;
        res.n = o.n;
        int* a = new int[o.n];
        res.x = a;
        for (int i = 0; i < this->n; i++)
            a[i] = this->x[i] + o.x[i];

        return res;
    }

    int prodottoScalare(const Vector& o) {
        if (this->n != o.n)
            throw (string)STR_ERR_N;

        int res = 0;
        for (int i = 0; i < this->n; ++i)
            res += this->x[i] * o.x[i];

        return res;
    }
};




#endif //VECTOR_VECTOR_H
