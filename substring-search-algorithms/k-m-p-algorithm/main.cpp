//
// Created by USER on 27/12/2021.
//

#include <iostream>

//space complexity O(M), time complexity O(N)

using namespace std;

const int NOT_FOUND = -1;

//PI table (partial match table)
void constructTable(char *pattern, int *table) {
    size_t m = strlen(pattern);
    table[0] = 0;

    int prefix_cnt = 0;
    int i = 1;

    // consider all letters of the pattern starting with index 1
    while (i < m) {
        if (pattern[i] == pattern[prefix_cnt]) {
            table[i++] = ++prefix_cnt;
        } else {
            if (prefix_cnt != 0) {
                // to see if curr letter continue new chain from the middle
                prefix_cnt = table[prefix_cnt - 1];
            } else {
                // we consider all options
                table[i++] = 0;
            }
        }

    }
}

int search(char *pattern, char *text) {
    size_t m = strlen(pattern);
    size_t n = strlen(text);

    int *table = new int[m];
    constructTable(pattern, table);
    //indexes to track the letters
    int i = 0;
    int j = 0;

    //KMP algorithm
    while (i < n && j < m) {
        if (text[i] == pattern[j]) {
            ++i;
            ++j;
            if (j == m) {
                cout << "Pattern found\n";
                delete[] table;
                return i - j;
            }
        } else if (i < n) {
            if (j != 0) {
                j = table[j - 1];
            } else {
                i++;
            }
        }
    }

    delete[] table;
    return NOT_FOUND;
}

int main() {
    char pattern[] = "ababd";
    char text[] = "ababcabcabaababd";
    int res = search(pattern, text);
    if (res != NOT_FOUND) {
        cout << text + res;
    }
}