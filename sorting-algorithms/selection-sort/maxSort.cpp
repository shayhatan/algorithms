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
int maxIndex(T data[], int n) {
    int max = 0;
    for (int i = 1; i < n; ++i) {
        if (data[i] > data[max]) {
            max = i;
        }
    }
    return max;
}

template<class T>
void maxSort(T data[], int n) {
    int max = 0;
    int len = n;
    for (int i = 0; i < n - 1; ++i) {
        max = maxIndex(data, len--);
        swap(data[len], data[max]);
    }
}


int main() {
    int data[] = {3, 2, 6, 6, 1, 4, -5, 1, 2, 3, -4, -2, 0};
    int n = sizeof(data) / sizeof(data[0]);

    maxSort(data, n);
    show(data, n);

    return 0;
}
