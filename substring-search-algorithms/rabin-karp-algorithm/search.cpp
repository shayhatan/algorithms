//
// Created by USER on 26/12/2021.
//
#include "hashes.h"
#include <iostream>

const int NOT_FOUND = -1;

//avg complexity O(N+M)
//complexity O(NM)
int search(char *str, char *pattern) {
    int m = strlen(pattern) + 1;
    int n = strlen(str) + 1;
    long double x_max_power = 0;

    double long p_key = hash(pattern, m, x_max_power);
    double long curr_key = hash(str, m, x_max_power);

    for (int i = 1; i <= n - m + 1; ++i) {
        if (p_key == curr_key) {
            int j = 0;
            for (; j < m; ++j) {
                if (pattern[j] != str[i + j - 1]) {
                    break;
                }
            }
            if (j == m) {
                return i - 1;
            }
        }
        curr_key = chainingHash(str, i, x_max_power, curr_key, m, n);
    }
    return NOT_FOUND;
}


int main() {
    char pattern[] = "test";
    char test[] = "This is a test";
    int index_path = search(test, pattern);
    if (index_path != NOT_FOUND) {
        std::cout << test + index_path;
    }
    return 0;
}
