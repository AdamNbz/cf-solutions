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
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(n));
    for (int i=n-1; i>=0; i--)
    {
        for (int j=i+1; j<n; j++)
        {
            for (int k=i; k<j; k++)
                ckmax(dp[i][j], dp[i][k] + dp[k+1][j]);
            for (int k=i+1; k<j; k++)
                ckmax(dp[i][j], dp[i+1][k-1] + dp[k+1][j-1] + a[i]*a[j]*a[k]);
        }
    }

    cout << dp[0][n-1] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}