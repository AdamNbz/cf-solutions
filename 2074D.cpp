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
    vector<ll> c(n); for (auto &x: c) cin >> x;
    vector<ll> r(n); for (auto &x: r) cin >> x;

    map<ll, vector<pair<ll, ll>>> mp;
    for (int i=0; i<n; i++)
    {
        ll st = c[i]-r[i], en = c[i]+r[i];
        for (ll x=st; x<=en; x++)
        {
            ll dx = x-c[i], dist = r[i]*r[i]-dx*dx;
            if (dist < 0) continue;

            ll y = ll(floor(sqrt(dist)));
            mp[x].push_back({-y, y});
        }
    }

    ll res = 0;
    for (auto x: mp)
    {
        auto &a = x.second;
        sort(a.begin(), a.end());
        ll crr[2] = {a[0].first, a[0].second}, cnt = 0;
        for (auto i=1; i<a.size(); i++)
        {
            if (a[i].first <= crr[1]+1) ckmax(crr[1], a[i].second);
            else
            {
                cnt += crr[1]-crr[0]+1;
                crr[0] = a[i].first, crr[1] = a[i].second;
            }
        }

        cnt += crr[1]-crr[0]+1;
        res += cnt;
    }
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) skibidi();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}