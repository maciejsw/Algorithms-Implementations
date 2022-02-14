#include <iostream>
using namespace std;

typedef struct element {
    int key;
    struct element* next;
}element;

void push(element** top, int value) {
    element* new_element = new element;
    new_element->key = value;
    new_element->next = *top;
    *top = new_element;
}

void pop(element** top) {
    cout << (*top)->key << endl;
    *top = (*top)->next;
}

void find(element** top, int search, int size) {
    element* temp;
    temp = *top;
    for (int i = size-1; i > search; i--) {
        temp = temp->next;
    }
    cout << temp->key << endl;
}

void freeMemory(element* top)
{
    element* i = top;

    while (i != 0)
    {
        top = i->next;
        delete i;
        i = top;
    }

    delete top;
}

int main() {
    int value, size=0, search;
    element* top = NULL;
    char command=0;
    while (command != 'q') {
        cin >> command;
        switch (command) {
        case 'i': {
            cin >> value;
            push(&top, value);
            size++;
            break;
        }
        case 'd': {
            if (top == NULL) cout << "!" << endl;
            else pop(&top);
            if(size>0)size--;
            break;
        }
        case 'g': {
            cin >> search;
            if (search >= size || top==NULL) cout << "?" << endl;
            else find(&top, search, size);
            break;
        }

        }
    }
    freeMemory(top);

    return 0;
}
