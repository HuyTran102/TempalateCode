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

int solve(int N) {
	int ans = 0;
	for(int i = N + 1; i <= N * N; i++) {
		ans ++;
	}
	return ans;
}

signed main() {
    fast_ios;
    // readInp("test.txt"); 
    // readInp("INPUT.INP");
    // writeOut("OUTPUT.OUT");
    int N;
    cin >> N;
	cout << solve(N) << endl;
    return 0;
}