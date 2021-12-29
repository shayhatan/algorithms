//
// Created by USER on 28/12/2021.
//
#include <iostream>

using namespace std;


//running time O(N!)
//it could be O(1) in quantum computers!!
template<class T>
void show(T data[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template<class T>
void swp(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

template<class T>
bool isSorted(T data[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (data[i + 1] < data[i]) {
            return false;
        }
    }
    return true;
}

// Fisher-Yates algorithm to shuffle the array
template<class T>
void shuffle(T data[], int n) {
    for (int i = n - 1; i >= 0; --i) {
        int j = (int) ((((double) rand() / RAND_MAX)) * i);
        swp(data[i], data[j]);
    }
}

template<class T>
void sort(T data[], int n) {
    int counter = 0;
    while (!isSorted(data, n)) {
        ++counter;
        shuffle(data, n);
    }
    cout << "Steps required to sort: " << counter << endl;
}

int main() {

    int data[] = {1, 100, 56, -3, 1, 2};
    int n = sizeof(data) / sizeof(data[0]);

    sort(data, n);
    show(data, n);
    return 0;
}