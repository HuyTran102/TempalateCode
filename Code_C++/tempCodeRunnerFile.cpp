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

int a[1005][1005], cnt[1005][1005];
int h, w;

signed main() {
    fast_ios;
    // freopen("test.txt", "r", stdin); 
    cin >> h >> w;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }

    cnt[0][1] = 1;

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(a[i][j] == '#') {
                cnt[i][j] = 0;
            } else {
                cnt[i][j] = (cnt[i - 1][j] + cnt[i][j - 1]) % MOD; 
            }
        }
    }
    cout << cnt[h][w] << endl;
    return 0;
}