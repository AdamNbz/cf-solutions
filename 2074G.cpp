#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using ll = long long;

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();
const int mxN = 401;

ll dp[mxN][mxN], a[mxN];

void skibidi()
{
    int n; cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) for (int j=i; j<=n; j++) dp[i][j] = 0;

    for (int i=3; i<=n; i++)
    {
        for (int j=1; j<=n+1-i; j++)
        {
            int k = j+i-1;
            ckmax(dp[j][k], dp[j+1][k]);
            ckmax(dp[j][k], dp[j][k-1]);
            for (int m=j+1; m<k; m++) ckmax(dp[j][k], dp[j+1][m-1]+dp[m+1][k-1]+a[j]*a[m]*a[k]);
        }
    }

    cout << dp[1][n] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}