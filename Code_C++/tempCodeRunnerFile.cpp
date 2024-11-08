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

int powerMod(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int sumMod(int a, int n) {
    if (a == 1) {
        return n % MOD;
    }
    int numerator = (a * (powerMod(a, n, MOD) - 1 + MOD) % MOD) % MOD;
    int denominator = powerMod(a - 1, MOD - 2, MOD); 
    return (numerator * denominator) % MOD;
}

signed main() { 
    fast_ios;
    // readInp("test.txt"); 
    // readInp("INPUT.INP");
    int a, n;
    cin >> a >> n;
    cout << sumMod(a, n) << endl;
    return 0;
}