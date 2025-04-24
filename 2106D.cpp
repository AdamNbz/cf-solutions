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
    vector<ll> a(n), b(m+1);
    for (auto &x: a) cin >> x;
    for (int i=1; i<=m; i++) cin >> b[i];

    vector<ll> pref(m+1, n);
    pref[0] = -1;
    int idx=0;
    for (int i=1; i<=m; i++)
    {
        while (idx < n && a[idx] < b[i]) idx++;
        if (idx < n) pref[i] = idx++;
    }
    if (pref[m] < n) 
    {
        cout << 0 << '\n';
        return;
    }

    vector<ll> suf(m+2, -1);
    suf[m+1] = n;
    idx = n-1;
    for (int i=m; i>=1; i--)
    {
        while (idx >= 0 && a[idx] < b[i]) idx--;
        if (idx >= 0) suf[i] = idx--;
    }

    ll ans = LLONG_MAX;
    for (int i=1; i<=m; i++) if (pref[i-1] < suf[i+1]) ckmin(ans, b[i]);
    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}