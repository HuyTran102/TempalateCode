#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define SZ(s) (int)s.size()
#define endl "\n"
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define to_s to_string
#define all(x) x.begin(),x.end()
#define setpr(x) cout << setprecision(x) << fixed
#define cin_test int test; cin >> test; while (test--)
#define fast_ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define readInp(fileName) freopen(fileName, "r", stdin)
#define writeOut(fileName) freopen(fileName , "w", stdout)
#define mapa(x, y) make_pair(x, y)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int LimN = 45;
const int LimM = 1e6 + 5;
const int INF = 1e18;
const int MOD = 1e9 + 7;
const double dist = 0.0000001;
 
void solve() {
    int k, a = 0;
    cin >> k;
    if (k > 1000000)
    {
        cout << k / 3 * 5 - 1;
        return ;
    }
    for (int i = 1; i <= k; i++)
    {
        a++;
        while (a % 3 == 0 || a % 10 == 3)
        {
            a++;
        }
    }
    cout << a;
}

signed main() { 
    // readInp("INPUT.INP");
    // writeOut("OUTPUT.OUT");
    // readInp("test.txt");
    fast_ios;
    // cin_test {
        // cin.ignore();
        solve();
    // }
    cerr << "Time elapsed: " << TIME << " s\n";
    return 0;
}

/* Authors: Tran Vu Gia Huy from Ngo Thi Nham Secondary school Da nang */