//Implement the sum of subsets problem with traceback.
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
vector<vector<int>> t;

bool sos(int n, vector<int>& a, int k) {
    if (k == 0) return true;
    if (n == 0) return false;
    if (dp[n][k] != -1) return dp[n][k];
    
    if (a[n - 1] <= k) {
        bool take = sos(n - 1, a, k - a[n - 1]);
        bool skip = sos(n - 1, a, k);
        if (take) t[n][k] = 1;
        else if (skip) t[n][k] = 2;
        return dp[n][k] = (take || skip);
    } else {
        bool skip = sos(n - 1, a, k);
        if (skip) t[n][k] = 2;
        return dp[n][k] = skip;
    }
}

void trace(vector<int>& a, int n, int k) {
    if (n == 0 || k == 0) return;
    if (t[n][k] == 1) {
        trace(a, n - 1, k - a[n - 1]);
        cout << a[n - 1] << " ";
    } else if (t[n][k] == 2) {
        trace(a, n - 1, k);
    }
}

int main() {
    vector<int> a = {2, 5, 8, 12, 6, 14};
    int k = 19;
    int n = a.size();

    dp.assign(n + 1, vector<int>(k + 1, -1));
    t.assign(n + 1, vector<int>(k + 1, -1));
    bool ans = sos(n, a, k);
    if (ans) {
        cout << "Yes\n";
        cout << "Subset sum is possible with the following elements: ";
        trace(a, n, k);
        cout << endl;
    } else {
        cout << "No\n";
    }

    return 0;
}
