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
	vector<vector<int>> a(6, vector<int>(6));
	pair<int, int> one;
	for (int i=1; i<=5; i++) for (int j=1; j<=5; j++) 
	{
		cin >> a[i][j];
		if (a[i][j] == 1) one = {i, j};
	}
	cout << abs(one.first-3)+abs(one.second-3);
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	skibidi();
	cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}