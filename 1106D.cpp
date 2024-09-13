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

int pop_cnt(ll mask) { return __builtin_popcountll(mask); }
int ctz(ull mask) { return __builtin_ctzll(mask); }
int logOf(ull mask) { return 63 - __builtin_clzll(mask); }

const ll mod = (ll)(1e9+7);
const ll inf = (ll)(2e18);
const ll mxN = (ll)(3e5+5);

v32 G[mxN];
vb visited;
priority_queue<int, vector<int>, greater<int>> q;
v32 ans;

void sol()
{
    int n, m; cin >> n >> m;
    visited.resize(n+1, 0);
    for (int i=0; i<m; i++)
    {
        int u, v; cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    visited[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int u = q.top(); q.pop();
        ans.pb(u);
        for (auto v: G[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = 1;
            }
        }
    }
    for (auto x: ans) cout << x << " ";
}

int32_t main()
{
    io();
    sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}