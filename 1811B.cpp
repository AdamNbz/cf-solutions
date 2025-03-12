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
    ll n; cin >> n;
    ll x[2], y[2]; cin >> x[0] >> y[0] >> x[1] >> y[1];
    if (n == 2)
    {
        cout << 0 << '\n';
        return;
    }

    cout << abs(min({x[0], y[0], n-x[0]+1, n-y[0]+1}) - min({x[1], y[1], n-x[1]+1, n-y[1]+1})) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}