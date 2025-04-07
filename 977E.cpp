/*
Author : Nguyen Vo Ngoc Bao
School : University of Information Technology, VNU-HCM
*/
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#ifndef ONLINE_JUDGE
   #if defined(__APPLE__)
      #include </Users/home/Documents/nbz_lib/debug.h>
   #elif defined(_WIN32) || defined(_WIN64)
      #include <C:/Users/Admin/OneDrive/Documents/nbz_lib/debug.h>
   #endif
#else
   #define dbg(...) 
#endif

#define nbzzz signed main
#define fi first
#define se second
#define el '\n'
#define pb push_back
#define eb emplace_back
#define io() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define mask(i) (1LL << (i))
#define getbit(mask, i) (((mask) >> (i)) & 1)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<ll> v64;
typedef vector<vector<ll> > vv64;
typedef vector<p32> vp32;
typedef vector<vector<p32> > vvp32;
typedef vector<p64> vp64;
typedef vector<vector<p64> > vvp64;
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
typedef vector<vs > vvs;

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int pop_cnt(ll mask) { return __builtin_popcountll(mask); }
int ctz(ull mask) { return __builtin_ctzll(mask); }
int logOf(ull mask) { return 63 - __builtin_clzll(mask); }
int parity(ull mask) { return __builtin_parityll(mask); }

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

struct dsu
{
    int n;
    vector<int> par, s, r;
    dsu(int _n): n(_n), par(n), s(n, 1), r(n, 0) { iota(all(par), 0); }
    int get(int u) { return u == par[u] ? u : par[u] = get(par[u]); }
    int disjointSet() { return n; }
    int sizes(int u) { return s[get(u)]; }
    bool same(int u, int v) { return get(u) == get(v); }
    bool unite(int u, int v) 
    {
        u = get(u), v = get(v);
        if (u == v) return 0;
        if (r[u] < r[v]) swap(u, v);
        par[v] = u;
        r[u] += r[u] == r[v];
        s[u] += s[v];
        --n;
        return 1;
    }
};

const int mxN = (int)(2e5);

void sol()
{
    int n, m; cin >> n >> m;
    dsu d(n);
    int dd[mxN], cyc[mxN];
    memset(cyc, -1, sizeof cyc);
    for (int i=0; i<m; i++)
    {
        int u, v; cin >> u >> v;
        --u, --v;
        dd[u]++, dd[v]++;
        d.unite(u, v);
    }
    int i, j;
    for (i=0; i<n; i++)
    {
        j = d.get(i);
        if (dd[i] != 2) cyc[j] = 0;
        else 
            if (cyc[j] == -1) cyc[j] = 1;
    }
    int ans = 0;
    for (i=0; i<n; i++) ans += (cyc[i] == 1);
    cout << ans;
}

nbzzz()
{
    io();
    sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}