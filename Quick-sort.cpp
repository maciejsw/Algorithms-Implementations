#include <iostream>
#include <string>
using namespace std;

bool compare(string a, string b) {
        if (a[0] == '-' && b[0] == '-') {
                if (a.size() > b.size()) return true;
                else if (a.size() < b.size()) return false;
                return (a > b);
        }
        else if (a[0] != '-' && b[0] == '-') return false;
        else if (a[0] == '-' && b[0] != '-') return true;
        else {
                if (a.size() < b.size()) return true;
                else if (a.size() > b.size()) return false;
                return (a < b);
        }
}


void quickSort(string numbers[], int left, int right) {
        int i = left, j = right;
        string pivot = numbers[(left + right) / 2];
        while (true) {
                while (compare(numbers[i], pivot)) i++;
                while (compare(pivot, numbers[j])) j--;
                if (i <= j) {
                        numbers[i].swap(numbers[j]);
                        i++;
                        j--;
                }
                else break;
        }
        if (left < j) quickSort(numbers, left, j);
        if (right > i) quickSort(numbers, i, right);
}

int main() {

        int n;
        cin >> n;
        string* numbers = new string[n];
        
        for (int i = 0; i < n; i++) {
                cin >> numbers[i];
        }
        quickSort(numbers, 0, n - 1);

        for (int i = 0; i < n; i++) {
                cout << numbers[i] << endl;
        }

        delete[] numbers;
        return 0;
}
