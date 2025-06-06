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

const int LimN = 1e2 + 5;
const int LimM = 1e2 + 5;
const int LimX = 1e6 + 5;
const int INF = 1e18;
const int MOD = 1e9 + 7;
const double dist = 0.0000001;

template <class X, class Y>
bool maximize(X &x, const Y &y) {
    if(x < y) {
        x = y;
        return true;
    }
    return false;
}

template <class X, class Y>
bool minimize(X &x, const Y &y) {
    if(x > y) {
        x = y;
        return true;
    }
    return false;
}

void add(int &x, const int &y) {
    x += y;
    if(x >= MOD) x -= MOD;
}

void sub(int &x, const int &y) {
    x -= y;
    if(x >= MOD) x += MOD;
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(const int &l, const int &r) {
    assert(l <= r);
    int sz = (r - l + 1);
    return l + rd() % sz;
}

// Chilling and coding

class SegmentTree {

private:

    int n;
    vi v, lazy;

    void push(int id, int l, int r, int mid) {
        if (lazy[id] == -1) return;

        lazy[id * 2] = lazy[id];
        lazy[id * 2 + 1] = lazy[id];

        v[id * 2] = lazy[id] * (mid - l + 1);
        v[id * 2 + 1] = lazy[id] * (r - mid);

        lazy[id] = -1;

    }

    void update(int id, int l, int r, int sta, int fin, int val) {

        if (sta > r || fin < l) {
            return;
        }

        if (sta <= l && r <= fin) {

            // v[id] = val * (r - l + 1);
            v[id] = val;
            lazy[id] = val;

            return;

        }

        int mid = (l + r) / 2;

        push(id, l, r, mid);

        update(id * 2, l, mid, sta, fin, val);
        update(id * 2 + 1, mid + 1, r, sta, fin, val);

        v[id] = v[id * 2] + v[id * 2 + 1];

    }



    // int get(int id, int l, int r, int sta, int fin) {

    //     if (sta > r || fin < l) {
    //         return 0;
    //     }

    //     if (sta <= l && r <= fin) {
    //         return v[id];
    //     }

    //     int mid = (l + r) / 2;

    //     push(id, l, r, mid);

    //     return __gcd(get(id * 2, l, mid, sta, fin), get(id * 2 + 1, mid + 1, r, sta, fin));

    // }

    int get(int id, int l, int r, int sta, int fin) {
        if (sta > r || fin < l) {
            return 0; // Out of range
        }

        if (sta <= l && r <= fin) {
            return v[id]; // Fully in range
        }

        int mid = (l + r) / 2;

        push(id, l, r, mid);

        return get(id * 2, l, mid, sta, fin) + get(id * 2 + 1, mid + 1, r, sta, fin);
    }

public:

    SegmentTree(int _n) {

        n = _n;

        v.resize(4 * n + 5, 0);

        lazy.resize(4 * n + 5, 0);

    }

    void resize(int _n) {

        n = _n;

        v.resize(4 * n + 5, 0);

        lazy.resize(4 * n + 5, 0);

    }

    void update(int sta, int fin, int val) {

        update(1, 1, n, sta, fin, val);

    }

    int get(int sta, int fin) {
        // return get(1, 1, n, sta, fin);
        return get(1, 0, n - 1, sta, fin);
    }

};

const int LENGTH = 1e6;
const int BASE = 256;

int pw[LENGTH + 5];

struct Hash {
    string s;
    int n;
    vector<int> pref;

    void init(const int _n, const string &_s) {
        s = _s;
        n = _n;
        s = "H" + s; // đưa về vị trí 1
        pref.resize(n + 1, 0);
    }

    void calc() {
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + s[i] * pw[i];
            pref[i] %= MOD;
        }
    }

    int get(int l, int r) {
        return (pref[r] - pref[l - 1] + MOD) % MOD * pw[LENGTH - r] % MOD;
    }
};


void solve() {

   


}

signed main() {
    // readInp("soanhca.inp");
    // writeOut("soanhca.out");
    // readInp("INPUT.INP");
    // writeOut("OUTPUT.OUT");
    // readInp("test.txt");
    fast_ios;
    bool PrintCase = 0;
    int _ = 1;
    // cin >> _;
    for (int i = 1; i <= _; i++) {
        if (PrintCase) cout << "Case" << " " << i << ": ";
        solve();
    }
    cerr << "Time elapsed: " << TIME << " s\n";
    return 0;
}

/* Authors: Tran Vu Gia Huy from Ngo Thi Nham Secondary school Da nang */



/* road to become a king */
