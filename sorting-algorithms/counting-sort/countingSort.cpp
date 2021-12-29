//
// Created by USER on 29/12/2021.
//

#include <iostream>

using namespace std;
// running time O(N + K)


// we want to create array in the size of (max number - min number + 1)
// in this case will just look at single digit values (1-10)
int const BUCKET_SIZE = 10;

void show(int *data, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

void copyArray(int a[], int b[], int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = b[i];
    }
}

// this is integer sorting approach (could be also characters)
void countingSort(int *data, int n) {
    int count[BUCKET_SIZE] = {0};
    int *output = new int[n];

    //first implementing histogram array
    for (int i = 0; i < n; ++i) {
        ++count[data[i]];
    }

    // build the cumulative in order to preserve stable sorting
    for (int i = 1; i < BUCKET_SIZE; ++i) {
        count[i] += count[i - 1];
    }

    // getting values for the out put array
    // MUST consider items in a reverse order in order to stability
    for (int i = n - 1; i >= 0; --i) {
        //--count[data[i]];
        output[--count[data[i]]] = data[i];
    }

    // finish -> memCopy
    copyArray(data, output, n);


    delete[] output;
}

int main() {
    int data[] = {3, 2, 6, 6, 1, 4, 1, 2, 3};
    int n = sizeof(data) / sizeof(data[0]);

    countingSort(data, n);
    show(data, n);

    return 0;
}