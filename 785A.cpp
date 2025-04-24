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
	int n; cin >> n;
	int ans = 0;
	for (int i=0; i<n; i++)
	{
		string s; cin >> s;
		ans += (s[0] == 'T' ? 4 : s[0] == 'C' ? 6 : s[0] == 'O' ? 8 : s[0] == 'D' ? 12 : s[0] == 'I' ? 20 : 0);
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	skibidi();
	cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}