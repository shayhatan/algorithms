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

//less intuitive implementation
template<class T>
void sort(T data[], int n) {
    int swapped = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n - i; ++j) {
            if (data[j - 1] > data[j]) {
                swap(data[j - 1], data[j]);
                swapped = true;
            }
        }
        if (!swapped) {
            return;
        }
    }
}

//more intuitive and basically the same
template<class T>
int bubble(T data[], int n) {
    int swapped = false;
    for (int i = 1; i < n; ++i) {
        if (data[i - 1] > data[i]) {
            swap(data[i - 1], data[i]);
            swapped = true;
        }
    }
    return swapped;
}

template<class T>
void bubbleSort(T data[], int n) {
    int swapped = true;
    while ((n > 1) && swapped) {
        swapped = bubble(data, n--);
    }
}

int main() {
    char data[] = {'c', 'b', 'a', 'e', 'd', 'g', 'f'};
    int n = sizeof(data) / sizeof(data[0]);

    char data2[] = {'c', 'b', 'a', 'e', 'd', 'g', 'f'};
    int k = sizeof(data2) / sizeof(data2[0]);

    sort(data, n);
    show(data, n);

    bubbleSort(data2, k);
    show(data2, k);

    return 0;
}