#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define el '\n'
#define pb push_back
#define eb emplace_back
#define io() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define mask(i) (1LL << (i))
#define getbit(mask, i) (((mask) >> (i)) & 1)
#define int long long

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<ll> v64;
typedef vector<vector<ll>> vv64;
typedef vector<p32> vp32;
typedef vector<vector<p32>> vvp32;
typedef vector<p64> vp64;
typedef vector<vector<p64>> vvp64;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

int pop_cnt(ll mask) { return __builtin_popcountll(mask); }
int ctz(ull mask) { return __builtin_ctzll(mask); }
int logOf(ull mask) { return 63 - __builtin_clzll(mask); }

const ll mod = (ll)(1e9 + 7);
const ll inf = (ll)(2e18);


void sol()
{
    int n, q, bad = 0;
    cin >> n >> q;
    v32 a(n, -1), p(n), dest(n), f(n);
    vector<set<int>> s(n);
    vv32 adj(n);
    for (int i = 1; i < n; i++) cin >> a[i], a[i]--;
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    for (int i = 0; i < n; i++) dest[p[i]] = i;
    
    for (int i = n - 1; i >= 0; i--) 
    {
        if (i > 0) adj[a[i]].eb(i);
        for (int j : adj[i]) f[i] += f[j];
        f[i]++;
    }
    
    auto cal = [&](int i) {
        if (s[i].empty()) return false;
        int x = dest[i];
        int y = *s[i].begin();
        return y < x;
    };

    auto remove = [&](int i, int x) {
        auto it = s[i].find(x);
        int l = -1, r = -1;
        if (it != s[i].begin()) 
        {
            l = *prev(it);
            bad -= (l + f[p[l]] != x);
        }
        if (next(it) != s[i].end()) 
        {
            r = *next(it);
            bad -= (x + f[p[x]] != r);
        }
        if (l != -1 && r != -1) 
        {
            bad += (l + f[p[l]] != r);
        }
        s[i].erase(it);
    };

    auto add = [&](int i, int x) {
        s[i].emplace(x);
        auto it = s[i].find(x);
        int l = -1, r = -1;
        if (it != s[i].begin()) 
        {
            l = *prev(it);
            if (l + f[p[l]] != x) bad++;
        }
        if (next(it) != s[i].end()) 
        {
            r = *next(it);
            bad += (x + f[p[x]] != r);
        }
        if (l != -1 && r != -1) 
        {
            bad -= (l + f[p[l]] != r);
        }
    };

    for (int i = 0; i < n; i++) {
        if (a[p[i]] != -1) add(a[p[i]], i);
    }

    for (int i = 0; i < n; i++) {
        bad += cal(i);
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        set<int> c;
        c.emplace(p[x]); c.emplace(p[y]); c.emplace(a[p[x]]); c.emplace(a[p[y]]);

        for (int z : c) if (z != -1) bad -= cal(z);

        if (a[p[x]] != -1) remove(a[p[x]], x);
        if (a[p[y]] != -1) remove(a[p[y]], y);

        swap(p[x], p[y]);
        swap(dest[p[x]], dest[p[y]]);

        if (a[p[x]] != -1) add(a[p[x]], x);
        if (a[p[y]] != -1) add(a[p[y]], y);
        for (int z : c) if (z != -1) bad += cal(z);
        cout << (!bad ? "YES\n" : "NO\n");
    }
}

int32_t main()
{
    io();
    int t;
    cin >> t;
    while (t--)
        sol();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}