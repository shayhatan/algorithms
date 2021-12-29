//
// Created by USER on 29/12/2021.
//

#include <iostream>

// O(N)

using namespace std;

const int BUCKET_SIZE = 10;

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
void countingSort(int data[], int n, int exp, int output[]) {
    int count[BUCKET_SIZE] = {0};


    //first implementing histogram array
    for (int i = 0; i < n; ++i) {
        ++count[(data[i] / exp) % 10];
    }

    // build the cumulative in order to preserve stable sorting
    for (int i = 1; i < BUCKET_SIZE; ++i) {
        count[i] += count[i - 1];
    }

    // getting values for the out put array
    // MUST consider items in a reverse order in order to stability
    for (int i = n - 1; i >= 0; --i) {
        /*--count[(data[i] / exp) % 10];*/
        output[--count[(data[i] / exp) % 10]] = data[i];
    }

    // finish -> memCopy
    copyArray(data, output, n);
}

int getMax(const int *data, int n) {

    int max = data[0];

    for (int i = 1; i < n; ++i) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

void radixSort(int data[], int n) {
    int max = getMax(data, n);
    int *output = new int[n];

    // we have as many iterations as number of digits
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(data, n, exp, output);
    }

    delete[] output;
}

int main() {
    int data[] = {1201, 1452, 8643, 1032, 3456, 1938};

    int n = sizeof(data) / sizeof(data[0]);

    radixSort(data, n);
    show(data, n);

    return 0;
}