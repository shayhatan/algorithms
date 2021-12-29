#include <iostream>

//consider as the best sorting algorithm although
// worse case running time complexity isn't the best (O(N^2) , space log(N))  = RARE
// avg case is O(Nlog(N)) ,space log(N)

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
int partition(T data[], int low, int high) {
    // middle index will be the pivot (we may generate a random value)
    int pivot_index = (low + high) / 2;

    //swap the pivot with the last item
    swap(data[pivot_index], data[high]);

    //consider all items

    int i = low;
    for (int j = low; j < high; ++j) {
        if (data[j] >= data[high]) {
            swap(data[j], data[i++]);
        }
    }
    swap(data[i], data[high]);

    return i;
}


template<class T>
void quickSort(T data[], int low, int high) {
    if (low >= high) {
        return;
    }

    // partition the actual array
    int pivot_index = partition(data, low, high);

    // on the left sub-array
    // ((pivot_index - 1): pivot_index already on his correct side)
    quickSort(data, low, pivot_index - 1);

    //on the right sub-array
    quickSort(data, pivot_index + 1, high);
}

int main() {
    int data[] = {3, 2, 6, 6, 1, 4, -5, 1, 2, 3, -4, -2, 0};
    int n = sizeof(data) / sizeof(data[0]);

    quickSort(data, 0, n-1);
    show(data, n);

    return 0;
}