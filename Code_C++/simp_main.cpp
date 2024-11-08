#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define endl "\n"
#define fast_ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define readInp(fileName) freopen(fileName, "r", stdin)
#define writeOut(fileName) freopen(fileName , "w", stdout)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int LimN = 1e6 + 5;
const int LimM = 1e6 + 5;
const int INF = 1e18;
const int MOD = 1e9 + 7;

signed main() {
    fast_ios;
    // freopen("test.txt", "r", stdin); 
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w));
    vector<vector<int>> dp(h, vector<int>(w, 0));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '#') continue; 
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD; 
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }

    // Xuất kết quả
    cout << dp[h-1][w-1] << endl;
    return 0;
}