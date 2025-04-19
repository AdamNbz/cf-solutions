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
    int n, k; cin >> n >> k;
    vector<ll> l(n), r(n);
    for (auto &x: l) cin >> x;
    for (auto &x: r) cin >> x;

    vector<ll> dist(n);
    ll s = 0;
    for (int i=0; i<n; i++)
    {
        dist[i] = min(l[i], r[i]);
        s += max(l[i], r[i]);
    }
    sort(dist.begin(), dist.end(), greater<ll>());

    ll ex = 0;
    for (int i=0; i+1<k && i<n; i++) ex += dist[i];
    cout << s+ex+1ll << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}