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
int minIndex(T data[], int n, int start) {
    int min = start;
    for (int i = start + 1; i < n; ++i) {
        if (data[i] < data[min]) {
            min = i;
        }
    }
    return min;
}

template<class T>
void minSort(T data[], int n) {
    int min = 0;
    for (int i = 0; i < n - 1; ++i) {
        min = minIndex(data, n, i);
        swap(data[i], data[min]);
    }
}

/*
int main() {
    int data[] = {3, 2, 6, 6, 1, 4, -5, 1, 2, 3, -4, -2, 0};
    int n = sizeof(data) / sizeof(data[0]);

    minSort(data, n);
    show(data, n);

    return 0;
}*/
