
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
void shellSort(T data[], int n) {

    //in final iteration we make standard insertion sort
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += gap) {
            int j = i;
            while (j >= gap && data[j - gap] > data[j]) {
                swap(data[j - gap], data[j]);
                j -= gap;
            }
        }
    }
}

int main() {
    int data[] = {3, 2, 6, 6, 1, 4, -5, 1, 2, 3, -4, -2, 0};
    int n = sizeof(data) / sizeof(data[0]);

    shellSort(data, n);
    show(data, n);

    return 0;
}