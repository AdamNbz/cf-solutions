#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using ll = long long;

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

struct dsu {
    int n;
    vector<int> par, s, r;
    vector<ll> w;

    dsu(int _n): n(_n), par(_n), s(_n,1), r(_n,0), w(_n,0)
    {
        iota(par.begin(), par.end(), 0);
    }

    int get(int u) 
    {
        return u == par[u] ? u : par[u] = get(par[u]);
    }

    bool same(int u, int v) 
    {
        return get(u) == get(v);
    }

    bool unite(int u, int v) 
    {
        u = get(u);
        v = get(v);
        if (u == v) return 0;
        if (r[u] < r[v]) swap(u,v);
        par[v] = u;
        s[u] += s[v];
        if (r[u] == r[v]) r[u]++;
        w[u] += w[v];
        --n;
        return 1;
    }

    ll weight(int u) 
    {
        return w[get(u)];
    }
};

void skibidi()
{
    int n; string s; cin >> n >> s;

    vector<pair<ll, ll>> sg;
    vector<ll> a(n, -1);
    for (int i=0; i<n; )
    {
        if (s[i] == '0') 
        {
            int l = i;
            while (i < n && s[i] == '0') i++;
            int r = i-1;
            sg.emplace_back(l, r);
            for (int j=l; j<=r; j++) a[j] = sg.size()-1;
        }
        else i++;
    }

    auto prefsum = [&](int x)
    {
        return 1ll*x*(x-1)/2;
    };

    int cnt = (sg.size()<<1), cnt2 = 0;
    vector<int> dg(n, -1);
    for (int i=0; i<n; i++) if (s[i] == '1') dg[i] = cnt + cnt2++;

    dsu d(cnt+cnt2);
    for (int i=0; i<sg.size(); i++)
    {
        auto x = sg[i];
        d.w[i] = prefsum(x.second+1) - prefsum(x.first);
        d.w[sg.size() + i] = (x.second-x.first+1)*(n-1) - prefsum(x.second+1) + prefsum(x.first);
    }
    for (int i=0; i<n; i++) if (s[i] == '1') d.w[dg[i]] = 1;

    for (int i=0; i<n; i++) 
    {
        if (s[i] == '1') 
        {
            int crr = dg[i];
            if (i >= 1 && s[i-1] == '0') d.unite(crr, sg.size() + a[i-1]);
            if (i < n-1 && s[i+1] == '0') d.unite(crr, a[i+1]);
        }
    }

    ll ans = 0;
    vector<char> vis(cnt+cnt2, 0);
    for (int u=0; u<cnt+cnt2; u++)
    {
        int v = d.get(u);
        if (!vis[v]) vis[v] = 1, ckmax(ans, d.w[v]);
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