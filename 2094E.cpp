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
    vector<int> a(n); for (auto &x: a) cin >> x;

    vector<int> cnt(30, 0);
    for (auto x: a) for (int i=0; i<30; i++) if (x&(1<<i)) cnt[i]++;

    ll ans = 0;
    for (auto x: a)
    {
        ll s = 0;
        for (int i=0; i<30; i++) 
            if (x&(1<<i)) s += ((1ll*(n-cnt[i]))<<i);
            else s += ((1ll*cnt[i])<<i);
        ckmax(ans, s);
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}