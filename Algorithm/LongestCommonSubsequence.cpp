//Longest Common Subsequence(LCS)
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> DP1;
vector<vector<int>> DP2;

//LCS using normal recursion
int LCSRecursion(vector<int>& x, vector<int>& y, int n, int m) {
    if (n == 0 || m == 0) return 0;
    else if (x[n - 1] == y[m - 1]) return 1 + LCSRecursion(x, y, n - 1, m - 1);
    else return max(LCSRecursion(x, y, n, m - 1), LCSRecursion(x, y, n - 1, m));
}

//LCS using normal recursion and Dynamic Programming 
int LCSDP(vector<int>& x, vector<int>& y, int n, int m) {
    if (n == 0 || m == 0) return DP1[n][m]=0;
    else if (x[n - 1] == y[m - 1]) return DP1[n][m]=(1 + LCSDP(x, y, n - 1, m - 1));
    else return DP1[n][m]=max(LCSDP(x, y, n, m - 1), LCSDP(x, y, n - 1, m));
}

//LCS using iteration and Dynamic Programming 
int LCSiter(vector<int>& x, vector<int>& y, int n, int m) {
    vector<vector<int>> DP2(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i - 1] == y[j - 1]) {
                DP2[i][j] = 1 + DP2[i - 1][j - 1];
            } else {
                DP2[i][j] = max(DP2[i - 1][j], DP2[i][j - 1]);
            }
        }
    }

    return DP2[n][m];
}


int main() {
    vector<int> x = {'A','K','B', 'D','A','K','B','D','L'};//BDAK
    vector<int> y = {'B','D', 'L','A','K'};//BDAK
    int n=x.size(),m=y.size();
    DP1.resize(n + 1, vector<int>(m + 1, -1));
    cout << LCSRecursion(x, y, n, m ) << "\n";
    cout << LCSDP(x, y, n, m) << "\n";
    cout << LCSiter(x, y, n, m) << "\n";
    return 0;
}