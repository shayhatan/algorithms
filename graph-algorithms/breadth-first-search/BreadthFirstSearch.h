//
// Created by USER on 22/12/2021.
//

#ifndef ALGORITHMS_BREATHFIRSTSEARCH_H
#define ALGORITHMS_BREATHFIRSTSEARCH_H
#include "Vertex.h"
#include <deque>
#include <memory>
#include <iostream>

class BreadthFirstSearch {
public:
    void operator()(Vertex *root) const;
};


#endif //ALGORITHMS_BREATHFIRSTSEARCH_H
