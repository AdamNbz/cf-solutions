#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using ll = long long;

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

void skibidi()
{
	string s; cin >> s;
	vector<int> st;
	for (auto x: s) if (x >= '0' && x <= '9') st.push_back((x-'0'));
	sort(st.begin(), st.end());
	string ans;
	for (auto x: st) ans += to_string(x) + "+";
	cout << ans.substr(0, ans.size()-1);
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	skibidi();
	cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}