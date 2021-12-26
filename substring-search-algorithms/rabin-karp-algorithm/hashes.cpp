//
// Created by USER on 26/12/2021.
//

#include "hashes.h"

const int X = 26;

const int NOT_FOUND = -1;

long double hash(const char *str, int m, long double &x_max_power) {
    int j = 0;
    long double res = 0;
    for (int i = m - 1; i >= 0; --i) {
        res += str[j++] * powl(X, i);
        if (i == m - 1) {
            x_max_power = res / str[j - 1];
        }
    }
    return res;
}

long double chainingHash(char *str, int curr, long double x_max_power, long double prev_key, int m, int n) {
    if (curr + m - 1 == n) {
        return NOT_FOUND;
    }
    long double new_sum = prev_key - str[curr - 1] * x_max_power;
    new_sum *= X;
    return new_sum + str[curr + m - 1];
}
