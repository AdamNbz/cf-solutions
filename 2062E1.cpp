/*
Author : Nguyen Vo Ngoc Bao
School : University of Information Technology, VNU-HCM
*/
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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
const int mxN = (int)(4e5+1);

v32 adj[mxN+1];
bool desMX[mxN+1];
int w[mxN+1], n;

bool dfs(int u, int p, int m)
{
    bool ok = (w[u] == m);
    for (auto v: adj[u])
    {
        if (v == p) continue;
        bool check = dfs(v, u, m);
        ok = (ok || check);
    }
    desMX[u] = ok;
    return ok;
}

void sol()
{
    // Easy version (i guess)
    cin >> n;
    int mx = 0;
    for (int i=1; i<=n; i++)
    {
        cin >> w[i];
        ckmax(mx, w[i]);
        adj[i].clear();
        desMX[i] = 0;
    }
    for (int i=1; i<n; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (n == 1)
    {
        cout << 0 << el;
        return;
    }

    dfs(1, -1, mx);
    int best = 0, ans = -1;
    for (int u=1; u<=n; u++)
    {
        if (!desMX[u])
        {
            if (w[u] < mx && w[u] > ans) ans = w[u], best = u;
        }
    }

    cout << abs(best) << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}