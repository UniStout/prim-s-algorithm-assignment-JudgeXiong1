//All procedures including main
#include "prim.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

void primMST(int n, const vector<vector<Edge>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> key(n, 1e9);
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);

    pq.push({ 0, 0 });
    key[0] = 0;

    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += w;

        for (const auto& edge : adj[u]) {
            if (!inMST[edge.to] && edge.weight < key[edge.to]) {
                key[edge.to] = edge.weight;
                parent[edge.to] = u;
                pq.push({ key[edge.to], edge.to });
            }
        }
    }
