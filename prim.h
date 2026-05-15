//Please put header information in this file.
#ifndef PRIM_H
#define PRIM_H

#include <vector>

struct Edge {
    int to;
    int weight;
};

// This tells the compiler that primMST exists elsewhere
void primMST(int n, const std::vector<std::vector<Edge>>& adj);
