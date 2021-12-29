//
// Created by USER on 28/12/2021.
//

#include <iostream>
//running time O(N^2)

template<class T>
void swap(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

template<class T>
void show(T data[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

template<class T>
void insertionSort(T data[], int n) {
    for(int i = 1; i < n; ++i) {

        //tracks the other items before item with index i
        int j = i;

        while ( j > 0 && data[j-1] > data[j]) {
            swap(data[j-1], data[j]);
            j--;
        }
    }
}

int main() {
    int data[] = {3, 2, 6, 6, 1, 4, -5, 1, 2, 3, -4, -2, 0};
    int n = sizeof(data) / sizeof(data[0]);

    insertionSort(data, n);
    show(data, n);

    return 0;
}