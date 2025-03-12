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
    int n, m; cin >> n >> m;
    vector<int> dp(n+1, n);
    dp[0] = 0;
    for (int i=0; i<m; i++)
    {
      int x, y; cin >> x >> y;
      if (x > y) swap(x, y);
      ckmin(dp[x], y-1);
    }
    for (int i=n-1; i>=0; i--) ckmin(dp[i], dp[i+1]);
    ll ans = n;
    for (int i=0; i<n; i++) ans += (1ll*dp[i]-i);
      cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}