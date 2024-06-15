#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> DP;
vector<vector<int>> DPU;

int boundknapsackRecusion(int n, vector<int>& w, vector<int>& v, int cap) {
    if (n == 0 || cap == 0) return 0;
    if (w[n - 1] <= cap) {
        return max(v[n - 1] + boundknapsackRecusion(n - 1, w, v, cap - w[n - 1]), boundknapsackRecusion(n - 1, w, v, cap));
    } else {
        return boundknapsackRecusion(n - 1, w, v, cap);
    }
}

int boundknapsackDP(int n, vector<int>& w, vector<int>& v, int cap) {
    if (n == 0 || cap == 0) return 0;
    if (DP[n][cap] != -1) return DP[n][cap];
    if (w[n - 1] <= cap) {
        return DP[n][cap] = max(v[n - 1] + boundknapsackDP(n - 1, w, v, cap - w[n - 1]), boundknapsackDP(n - 1, w, v, cap));
    } else {
        return DP[n][cap] = boundknapsackDP(n - 1, w, v, cap);
    }
}

int unboundknapsackRecusion(int n, vector<int>& w, vector<int>& v, int cap) {
    if (n == 0 || cap == 0) return 0;
    if (w[n - 1] <= cap) {
        return max(v[n - 1] + unboundknapsackRecusion(n, w, v, cap - w[n - 1]), unboundknapsackRecusion(n - 1, w, v, cap));
    } else {
        return unboundknapsackRecusion(n - 1, w, v, cap);
    }
}

int unboundknapsackDP(int n, vector<int>& w, vector<int>& v, int cap) {
    if (n == 0 || cap == 0) return 0;
    if (DPU[n][cap] != -1) return DPU[n][cap];
    if (w[n - 1] <= cap) {
        return DPU[n][cap] = max(v[n - 1] + unboundknapsackDP(n, w, v, cap - w[n - 1]), unboundknapsackDP(n - 1, w, v, cap));
    } else {
        return DPU[n][cap] = unboundknapsackDP(n - 1, w, v, cap);
    }
}

int main() {
    vector<int> w = {10, 20, 30};
    vector<int> v = {60, 100, 120};
    int n = w.size();
    int capacity = 50;
    DP.resize(n + 1, vector<int>(capacity + 1, -1));
    DPU.resize(n + 1, vector<int>(capacity + 1, -1));
    cout << boundknapsackRecusion(n, w, v, capacity) << "\n";
    cout << boundknapsackDP(n, w, v, capacity) << "\n";
    cout << unboundknapsackRecusion(n, w, v, capacity) << "\n";
    cout << unboundknapsackDP(n, w, v, capacity) << "\n";
}