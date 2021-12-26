//
// Created by USER on 26/12/2021.
//

#ifndef ALGORITHMS_HASHES_H
#define ALGORITHMS_HASHES_H
#include <cmath>

long double hash(const char *str, int m, long double &x_max_power);

long double chainingHash(char* str, int curr, long double x_max_power, long double prev_key, int m, int n);

#endif //ALGORITHMS_HASHES_H
