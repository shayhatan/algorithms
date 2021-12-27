//
// Created by USER on 27/12/2021.
//
#include <iostream>

using namespace std;

void constructTable(string s, int *table) {
    //first item in Z table inst important
    table[0] = (int) s.length();

    //pointing the Z box
    int left = 0;
    int right = 0;

    //consider all the letters of S string
    for (int k = 1; k < table[0]; ++k) {
        // CASE 1 -
        // naive formula - out side a scope of a Z box
        if (k > right) {
            int n = 0;
            while (n + k < table[0] && s[n] == s[n + k]) {
                ++n;
            }
            table[k] = n;

            //we may update the left and right values
            //because Z boxes are created there are MATCHING letters
            if (n > 0) {
                left = k;
                right = n + k - 1;
            }
        } else {
            //CASE 2 -
            //we may copy the value from the Z table we have already computed
            // (if the rest of the string smaller then the size of the computed value)
            int p = k - left;
            if (table[p] < right - k + 1) {
                table[k] = table[p];
            } else {
                //CASE 3 -
                //means that the size of the computed value is grater then the rest of string in Z box
                int i = right + 1;
                while (i < table[0] && s[i] == s[i - k]) {
                    ++i;
                }
                table[k] = i - k;
                left = k;
                right = k - 1;
            }
        }
    }
}

void search(string patter, string txt) {
    //we have to combine the text and the pattern
    string s = patter + txt;

    //construct the z table
    int *table = new int[s.length()];
    constructTable(s, table);

    // now we just have to consider the Z table values
    for (int i = 1; i < table[0]; ++i) {
        if (table[i] >= patter.length()) {
            cout << "Pattern found at index: " << i - patter.length() << endl;
        }
    }
}

int main() {
    char pattern[] = "test";
    char text[] = "this is a test";

    search(pattern, text);
}