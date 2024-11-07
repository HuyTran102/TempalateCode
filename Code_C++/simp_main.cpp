#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define endl "\n"
#define fast_ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define readInp(fileName) freopen(fileName, "r", stdin)
#define writeOut(fileName) freopen(fileName , "w", stdout)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int LimN = 1e5 + 5;
const int LimM = 1e6 + 5;
const int INF = 1e18;
const int MOD = 1e9 + 7;

signed main() { 
    fast_ios;
    // readInp("test.txt"); 
    // readInp("INPUT.INP");
    int n, m, P;
    cin >> n >> m >> P;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    vector<vector<int>> x(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            x[i][j] = a[i] * b[j];
        }
    }

    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pref[i][j] = x[i-1][j-1]
                             + pref[i-1][j]
                             + pref[i][j-1]
                             - pref[i-1][j-1];
        }
    }

    int count = 0;
    for (int i1 = 1; i1 <= n; i1++) {
        for (int i2 = i1; i2 <= n; i2++) {
            for (int j1 = 1; j1 <= m; j1++) {
                for (int j2 = j1; j2 <= m; j2++) {
                    int rect_sum = pref[i2][j2]
                                - pref[i1 - 1][j2]
                                - pref[i2][j1 - 1]
                                + pref[i1 - 1][j1 - 1];
                    if (rect_sum <= P) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}