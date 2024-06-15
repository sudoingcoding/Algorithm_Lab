//Write a Program that takes an undirected graph as input and apply BFS to find shortest path from source node to all other node with corresponding cost
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
vector<int> dist;

void BFS(int src) {
    int V = adjList.size();
    dist.assign(V, INT_MAX);
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbour : adjList[node]) {
            if (dist[neighbour] > dist[node] + 1) {
                dist[neighbour] = dist[node] + 1;
                q.push(neighbour);
            }
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    adjList.resize(v);
    for (int i = 0; i < e; i++) {
        int from, to;
        cin >> from >> to;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }
    for (int i = 0; i < v; i++) {
        BFS(i);
        cout << "Shortest distances from node " << i << ":\n";
        for (int j = 0; j < v; j++) {
            cout << "Vertex " << j << ": ";
            if (dist[j] == INT_MAX) {
                cout << "No path\n";
            } else {
                cout << dist[j] << "\n";
            }

        }
    }

    return 0;
}
