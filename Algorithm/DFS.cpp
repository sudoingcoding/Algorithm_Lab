//Write a Program that takes a directed graph as input and applies DFS to classify each node as either tree or back or forward or cross edge.
#include<bits/stdc++.h>
using namespace std;

class graph {
public:
    vector<vector<int>> adjList;
    vector<vector<int>> color;
    vector<int> visited;
    int V;

    void enter() {
        int v, e;
        cin >> v >> e;
        V = v;

        adjList.resize(v);
        for (int i = 0; i < e; i++) {
            int from, to;
            cin >> from >> to;
            adjList[from].push_back(to);
            // For directed graph, no need to add reverse edge
        }
    }

    void DFS(int src) {
        visited.assign(V, false);
        color.assign(V, vector<int>(V, 0)); // Initialize color matrix

        DFSVisit(src);
    }

    void DFSVisit(int u) {
        visited[u] = true;

        for (int v : adjList[u]) {
            if (!visited[v]) {
                // Tree Edge
                color[u][v] = 1;
                DFSVisit(v);
            } else {
                // Back Edge, Forward Edge, or Cross Edge
                if (color[v][u] == 0) {
                    // Back Edge
                    color[u][v] = 2;
                } else if (color[u][v] == 0) {
                    // Forward Edge
                    color[u][v] = 3;
                } else {
                    // Cross Edge
                    color[u][v] = 4;
                }
            }
        }
    }
};

int main() {
    graph g;
    g.enter();
    g.DFS(0);

    cout << "Classification of edges:\n";
    for (int u = 0; u < g.V; u++) {
        for (int v = 0; v < g.V; v++) {
            if (g.color[u][v] == 1) {
                cout << "Tree Edge: " << u << " -> " << v << "\n";
            } else if (g.color[u][v] == 2) {
                cout << "Back Edge: " << u << " -> " << v << "\n";
            } else if (g.color[u][v] == 3) {
                cout << "Forward Edge: " << u << " -> " << v << "\n";
            } else if (g.color[u][v] == 4) {
                cout << "Cross Edge: " << u << " -> " << v << "\n";
            }
        }
    }

    return 0;
}
