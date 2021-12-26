#include <iostream>

using namespace std;
const int NOT_FOUND = -1;

int search(char *pattern, char *text) {
    size_t m = strlen(pattern);
    size_t n = strlen(text);

    for (int i = 0; i < n - m + 1; ++i) {

        //tracks the letters in the pattern
        int j = 0;

        for (; j < m; ++j) {
            if (pattern[j] != text[i + j]) {
                break;
            }
        }

        if (j == m) {
            return i;
        }
    }
    return NOT_FOUND;
}

int main() {
    char pattern[] = "test";
    char test[] = "This is a test";
    int index_path = search(pattern, test);
    if (index_path != NOT_FOUND) {
        cout << test + index_path;
    }
    return 0;
}