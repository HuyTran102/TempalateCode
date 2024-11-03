#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define endl "\n"
#define fast_ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define readInp(fileName) freopen(fileName, "r", stdin)
#define writeOut(fileName) freopen(fileName , "w", stdout)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

const int LimN = 2e5 + 5;
const int LimM = 1e6 + 5;
const int INF = 1e18;
const int MOD = 1e9 + 7;

int a[LimN], b[LimN], sp[LimN], par[LimN];

int calc(int n){
    if (!par[n]) return n;
    return (par[n] = calc(par[n]));
}

signed main() {
    fast_ios;
    // readInp("test.txt"); 
    // readInp("INPUT.INP");
    // writeOut("OUTPUT.OUT");
    int x, n;
    cin >> x >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    b[n + 1] = x;

    int tmp = 0;
    for(int i = 1; i <= n + 1; i++){
        sp[i] = i - 1;
        tmp = max(tmp, b[i] - b[i - 1]);
    }

    stack<int> st;
    for(int i = n; i > 0; i--){
        st.push(tmp);
        int pos = lower_bound(b + 1, b + n + 1, a[i]) - b;
        int res = calc(pos + 1);
        tmp = max(tmp, b[res] - b[sp[pos]]);
        sp[res] = sp[pos];
        par[pos] = res;
    }
    while (!st.empty()){
        cout << st.top() << "\n";
        st.pop();
    }
    return 0;
}