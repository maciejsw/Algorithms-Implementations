#include <iostream>
using namespace std;

#define MAX_SIZE 1000

int Parent(int i){
        return (i-1)/2; 
}

int Left(int i){
        return (i * 2) + 1;
}

int Right(int i){
        return (i * 2) + 2;
}

void MaxHeap(int tab[], int n, int i){
        int left = Left(i);
        int right = Right(i);
        int maks = i;
        if (left < n && tab[left] > tab[maks]) maks = left;
        if (right < n && tab[right] > tab[maks]) maks = right;
        if (maks != i){
                swap(tab[i], tab[maks]);
                MaxHeap(tab, n, maks);
        }
}

void MinHeap(int tab[], int n, int i) {
        int left = Left(i);
        int right = Right(i);
        int mini = i;
        if (left < n && tab[left] < tab[mini]) mini = left;
        if (right < n && tab[right] < tab[mini]) mini = right;
        if (mini != i) {
                swap(tab[i], tab[mini]);
                MinHeap(tab, n, mini);
        }
}

void BuildMaxHeap(int tab[], int n){
        for (int i = Parent(n); i >= 0; i--) MaxHeap(tab, n, i);
}

void BuildMinHeap(int tab[], int n){
        for (int i = Parent(n); i >= 0; i--) MinHeap(tab, n, i);
}

void MaxInsert(int tab[], int n, int value){
        tab[n] = value;
        int i = n;

        while ((i != 0))
        {
                if (tab[Parent(i)] < tab[i]) {
                        swap(tab[Parent(i)], tab[i]);
                        i = Parent(i);
                }
                else return;
        }
}

void MinInsert(int tab[], int n, int value) {
        tab[n] = value;
        int i = n;

        while ((i != 0))
        {
                if (tab[Parent(i)] > tab[i]) {
                        swap(tab[Parent(i)], tab[i]);
                        i = Parent(i);
                }
                else return;
        }
}

void MaxDelete(int tab[], int n) {
        cout << tab[0] << endl;
        if (!n) return;
        swap(tab[0], tab[n-1]);
        tab[n-1] = NULL;
        n--;
        MaxHeap(tab, n, 0);
}

void MinDelete(int tab[], int n) {
        cout << tab[0] << endl;
        if (!n) return;
        swap(tab[0], tab[n-1]);
        tab[n-1] = NULL;
        n--;
        MinHeap(tab, n, 0);
}

int main(){
        int size = 0;
        int value;
        char command=' ';
        int tab[MAX_SIZE];
        bool order = 0;
        while (command != 'q')
        {
                cin >> command;
                switch (command)
                {
                case '+':
                        cin >> value;
                        if (!order) {
                                MaxInsert(tab, size, value);
                                size++;
                                BuildMaxHeap(tab, size);
                        }
                        else {
                                MinInsert(tab, size, value);
                                size++;
                                BuildMinHeap(tab, size);
                        }
                        break;
                case '-':
                        if (!order) MaxDelete(tab, size);
                        else MinDelete(tab, size);
                        if (size)size--;
                        break;
                case 'p':
                        for (int i = 0; i < size; i++) cout << tab[i] << " ";
                        if (size)cout << endl;
                        break;
                case 'r':
                        cin >> size;
                        for (int i = 0; i < size; i++) cin >> tab[i];
                        if (!order)BuildMaxHeap(tab, size);
                        else BuildMinHeap(tab, size);
                        break;
                case 's':
                        if (!order) {
                                order = 1;
                                BuildMinHeap(tab, size);
                        }
                        else {
                                order = 0;
                                BuildMaxHeap(tab, size);
                        }
                        break;
                }
        }
        return 0;
}
