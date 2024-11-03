#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pairll pair<ll,ll>
#define pairiii pair<ll, pairll>
using namespace std;
const int N = 1e5 + 5, mod = 1e9 + 7, base = 256, limit = 1e9 + 5;
struct SegMentTree {
	ll stsum[N * 4], stsl[N * 4];
	void updatesum (ll id, ll l, ll r, ll pos, ll val) {
		if (pos < l || r < pos)
			return;
		if (l == r) 
			return stsum[id] = val;
		ll mid = (l + r) / 2;
		update (id * 2, l, mid, pos, val);
		update (id * 2 + 1, mid + 1, r, pos, val);	
		stsum[id] = stsum[id * 2] + stsum[id * 2 + 1];
	}
	ll getsum (ll id, ll l, ll r, ll u, ll v) {
		if (u <= l && r <= v)
			return stsum[id];
		if (v < l || r < u)
			return 0;
		ll mid = (l + r) / 2;
		return getsum (id * 2, l, mid, u, v) + getsum (id * 2 + 1, mid + 1, u, v);
	}
	
	void updatesl (ll id, ll l, ll r, ll pos, ll val) {
		if (pos < l || r < pos)
			return;
		if (l == r) 
			return stsl[id] = val;
		ll mid = (l + r) / 2;
		update (id * 2, l, mid, pos, val);
		update (id * 2 + 1, mid + 1, r, pos, val);	
		stsl[id] = stsl[id * 2] + stsl[id * 2 + 1];
	}
	ll getsl (ll id, ll l, ll r, ll u, ll v) {
		if (u <= l && r <= v)
			return stsum[id];
		if (v < l || r < u)
			return 0;
		ll mid = (l + r) / 2;
		return getsum (id * 2, l, mid, u, v) + getsum (id * 2 + 1, mid + 1, u, v);
	}
};
xaucon (ll l, ll r, ll socanbang) {
	ll sumbe = st.updatesum (1, 1, n, nenso[l - 1],  - s[l - 1]);
	ll sl_be = st.updatesl (1, 1, n, nenso[l - 1],  - 1);
	ll sumlon = st.updatesum (1, 1, n, nenso[r], s[r]);
	ll sllon = st.updatesl (1, 1, n, nenso[r], 1);
		
	return (socanbang * sl_be - sumbe) + (sumlon - sl_lon * socanbang);
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
	}
	deque <ll> d[N];
	priority_queue <pairiii, vector<pairiii>, greater<pairiii> > pq;
	for (int i = 1; i <= k; i ++) {
		d[s[i]].push_back(i);
	}
	
	for (int i = 1; i <= k; i ++) {
		if (kt[s[i]] == false) {
			// so luong, vi tri bat dau, gtri
			pq.push ({d[s[i]].size(), {i, s[i]}})
		}
	}
	// 1 toi k thi minh se dung thang pq.top().se.se de can bang
	// (thang nay co so luong la pq.top(), fi)
	ans.push_back (pq.top().se.se); 
	
	// xet toi nhung nho'm 2 -> k + 1, 3 -> k + 2, ...
	for (int i = 2; i <= n; i ++) {
		// 1 -> k 
		// bien len thanh 2 -> k + 1
		// luoc bo di thang s[i - 1]
		d[s[i - 1]].pop_front();
		if (!d[s[i - 1]].empty()) //gia tri s[i - 1] con ton tai trong xau
			pq.push_back ({d[s[i - 1]].size(), {d[s[i - 1]].front(), s[i - 1]}});
		// them vao thang s[i + 1]
		d[s[i + 1]].push_back (i + k);
		
		pq.push_back ({d[s[i + k]].size(), {d[s[i + k]].front(), s[i + 1]}});
		
		//vi tri be hon i hien tai
		// => gia tri nay duoc cap nhat khi vi tri < i
		// ko dung dc 
		while (pq.top().se.fi < i) 
			pq.pop();
		// xau co do dai k bat dau tu i se dung thang s[i] de lam gia tri can bang
		// voi so luong s[i] la d[s[i].size()
		ans.push_back (s[i]);
	}
	
	for (int i = 0; i < ans.size(); i ++) {
		cout << xaucon (i + 1, i + k, ans[i]) << ' ';
	}
}
int main() {
//	ios_base::sync__with_stdio(0);
//	cin.tie(0);cout.tie(0);
	ll testcase = 1;
//	cin >> testcase;
	while (testcase --)
		solve();
}
//road to national prize