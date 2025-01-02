#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pii pair<int, int>
#define mii map<int, int>
#define umap unordered_map
#define uset unordered_set
#define si set<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define SZ(s) (int) s.size()
#define endl "\n"
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a / gcd(a, b)) * b
#define lb lower_bound // dùng cho trường hợp >=
#define ub upper_bound // dùng cho trường hợp >
#define pushb push_back
#define pushf push_front
#define popb pop_back
#define popf pop_front
#define fi first
#define se second
#define to_s to_string
#define all(x) x.begin(), x.end()
#define debug cout << "NO ERROR", exit(0)
#define setpr(x) cout << setprecision(x) << fixed
#define fast_ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define readInp(fileName) freopen(fileName, "r", stdin)
#define writeOut(fileName) freopen(fileName , "w", stdout)
#define mapa(x, y) make_pair(x, y)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int LimN = 45;
const int LimM = 1e6 + 5;
const int INF = 1e18;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const double dist = 0.0000001;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(const int &l, const int &r) {
    assert(l <= r);
    int sz = (r - l + 1);
    return l + rd() % sz;
}
 
void solve() {
    
}

signed main() {
    // readInp("INPUT.INP");
    // writeOut("OUTPUT.OUT");
    // readInp("test.txt");
    fast_ios;
    bool PrintCase = 0;
    int _ = 1;
    //cin >> _;
    for (int i = 1; i <= _; i++) {
        if (PrintCase) cout << "Case" << " " << i << ": ";
        solve();
    }
    cerr << "Time elapsed: " << TIME << " s\n";
    return 0;
}

/* Authors: Tran Vu Gia Huy from Ngo Thi Nham Secondary school Da nang */



/* road to become a king*/