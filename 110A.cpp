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
	string n; cin >> n;
	int cnt4 = 0, cnt7 = 0;
	for (int i=0; i<n.size(); i++)
	{
		cnt4 += (n[i] == '4'), cnt7 += (n[i] == '7');
	}
	cout << (cnt4+cnt7 == 4 || cnt4+cnt7 == 7 ? "YES" : "NO");
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	skibidi();
	cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}