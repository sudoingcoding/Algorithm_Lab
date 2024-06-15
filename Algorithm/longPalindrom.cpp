//Find the longest palindromic subsequence from a sequence using DP
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<vector<int>> t;

int lcs(string x, string y, int n, int m) {
    if (n == 0 || m == 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];

    if (x[n - 1] == y[m - 1]) {
        t[n][m] = 1;
        return dp[n][m] = 1 + lcs(x, y, n - 1, m - 1);
    } else {
        int l1 = lcs(x, y, n - 1, m);
        int l2 = lcs(x, y, n, m - 1);
        if (l1 > l2) {
            t[n][m] = 2;
            return dp[n][m] = l1;
        } else {
            t[n][m] = 3;
            return dp[n][m] = l2;
        }
    }
}

void trace(string x, string y, int n, int m) {
    if (n == 0 || m == 0) return;
    if (t[n][m] == 1) {
        trace(x, y, n - 1, m - 1);
        cout << x[n - 1] << "\n";
    } else if (t[n][m] == 2) {
        trace(x, y, n - 1, m);
    } else {
        trace(x, y, n, m - 1);
    }
}

int main() {
    string x = "AGGTAB";
    string y = x;
    reverse(y.begin(),y.end());
    int n = x.size();
    int m = y.size();

    dp.assign(n + 1, vector<int>(m + 1, -1));
    t.assign(n + 1, vector<int>(m + 1, -1));

    cout << "Length of LCS: " << lcs(x, y, n, m) << "\n";
    cout << "LCS Sequence: \n";
    trace(x, y, n, m);
    return 0;
}



