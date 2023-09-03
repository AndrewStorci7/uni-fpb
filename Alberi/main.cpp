#include <iostream>
using namespace std;

template <class T>
class AlberoBinario {
private:
    T data;
    AlberoBinario<T>* left;
    AlberoBinario<T>* right;
public:
    AlberoBinario(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    void add(const T& d, AlberoBinario<T>& a) {
        if (sizeof d == sizeof this->data) {
            if (this->data > d && this->left == NULL) {
                AlberoBinario<T>* new_tree = new AlberoBinario<T>(d);
                this->left = new_tree;
            } else if (this->data < d && this->right == NULL) {
                AlberoBinario<T>* new_tree = new AlberoBinario<T>(d);
                this->right = new_tree;
            } else return (this->data > d) ? add(d, a.left) : add(d, a.right);
        } else
            throw invalid_argument("Tipo di dato non corretto");
    }

     

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
