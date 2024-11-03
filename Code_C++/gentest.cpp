
#include<bits/stdc++.h>
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(const int &l, const int &r) {
    assert(l <= r);
    int sz = (r - l + 1);
    return l + rd() % sz;
}

signed main() {
    freopen("test.txt", "w", stdout);
    int a = Rand(1, 1000);
    int b = Rand(1, 1000);
    cout << a << " " << b << endl;
    return 0;
}