#include <iostream>
using namespace std;

struct node {
    char data;
    node* next;
};

void add(node* &head, char s) {
    node* newNode = new node;
    newNode->data = s;
    newNode->next = head;
    head = newNode;
}

void print(node* &head) {
    if (head == NULL)
        cout << "Lista vuota" << endl;
    else if (head->next != NULL) {
        cout << head->data << " -> ";
        return print(head->next);
    } else
        cout << head->data << " -> NULL" << endl;
}

void concat(node* &l1, node* &l2) {
    if (l1 == NULL && l2 == NULL)
        return;
    else if (l1->next != NULL) {
        return concat(l1->next, l2);
    } else
        l1->next = l2;
}

void revert(char s[]) {
    int size = 0;
    char tmp;
    while (s[size] != '\0')
        size++;
    for (int i = 0; i < size; i++) {
        if (i <= size / 2) {
            tmp = s[i];
            s[i] = s[(size - 1) - i];
            s[(size - 1) - i] = tmp;
        }
    }
}

int main() {
    char str[] = "hello";
    cout << str << endl;
    revert(str);
    cout << str << endl;

    int* a = new int[1000]();
    int n = 0, size = 0;
    while (true) {
        if (size >= 1000) {
            cout << "Spazio esaurito" << endl;
            break;
        }
        cout << "Inserisci un numero intero positivo: ";
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(100000, '\n');
        } else if (n < 0) {
            cout << "Hai inserito un numero negativo" << endl;
            break;
        } else {
            a[size] = n;
            size++;
        }
    }

    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << a[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << " ]" << endl;

    int* b = new int[size];
    int count, i_b = 0;
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int y = 0; y < size; y++)
            if (a[i] == a[y])
                count++;
        if (count == 1) {
            b[i_b] = a[i];
            i_b++;
        }
    }

    cout << "[ ";
    for (int i = 0; i < i_b; i++) {
        cout << b[i];
        if (i < i_b - 1)
            cout << ", ";
    }
    cout << " ]" << endl;

    delete[] a;
    delete[] b;

    node* head = NULL;
    node* head_2 = NULL;
    for (int i = 0; i < 5; i++)
        add(head, 97 + rand() % 25);
    for (int i = 0; i < 3; i++)
        add(head_2, 97 + rand() % 25);
    print(head);
    print(head_2);
    concat(head, head_2);
    print(head);
    print(head_2);
    return 0;
}
