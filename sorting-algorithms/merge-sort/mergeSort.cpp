//
// Created by USER on 28/12/2021.
//
#include <iostream>

// time: O(Nlog(N)) space: O(N)

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
void copyArray(T a[], T b[], int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = b[i];
    }
}

template<class T>
void merge(T a[], int n_a, T b[], int n_b, T helper[]) {
    int i_a = 0;
    int i_b = 0;
    int i_c = 0;
    for (; (i_a < n_a) && (i_b < n_b); ++i_c) {
        if (a[i_a] < b[i_b]) {
            helper[i_c] = a[i_a++];
        } else {
            helper[i_c] = b[i_b++];
        }
    }
    for (; i_a < n_a; ++i_c, ++i_a) {
        helper[i_c] = a[i_a];
    }
    for (; i_b < n_b; ++i_c, ++i_b) {
        helper[i_c] = b[i_b];
    }
}

template<class T>
void recMerge(T data[], T help_arr[], int n) {
    int left = n / 2;
    int right = n - left;

    //base case is when we have only one item in the sub-array
    if (n < 2) {
        return;
    }
    recMerge(data, help_arr, left);
    recMerge(data + left, help_arr, right);
    merge(data, left, data + left, right, help_arr);
    copyArray(data, help_arr, n);

}

template<class T>
void mergeSort(T data[], int n) {
    T *helper_arr = new T[n];
    recMerge(data, helper_arr, n);
    delete[] helper_arr;
}

int main() {
    int data[] = {3, 2, 6, 6, 1, 4, -5, 1, 2, 3, -4, -2, 0};
    int n = sizeof(data) / sizeof(data[0]);

    mergeSort(data, n);
    show(data, n);

    return 0;
}