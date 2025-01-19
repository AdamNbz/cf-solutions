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

struct dsu {
    int n;
    v32 p, r;
    dsu(int n_) : n(n_), p(n_+1), r(n_+1, 1) {
        for(int i=1; i<=n; i++) p[i] = i;
    }
    int find_set(int x) {
        if(p[x] == x) return x;
        return p[x] = find_set(p[x]);
    }
    void union_set(int x, int y) {
        x = find_set(x); 
        y = find_set(y);
        if (x != y)
        {
            if (r[x] < r[y]) swap(x,y);
            p[y] = x;
            if(r[x] == r[y]) r[x]++;
        }
    }
};

void sol()
{
    int n, m1, m2; cin >> n >> m1 >> m2;
    vp32 eF(m1), eG(m2);
    for (int i=0; i<m1; i++) cin >> eF[i].fi >> eF[i].se;
    for (int i=0; i<m2; i++) cin >> eG[i].fi >> eG[i].se;

    if (n == 1) 
    {
        cout << 0 << el;
        return;
    }

    dsu G(n);
    for (auto &e: eG)
    {
        int u = e.fi, v = e.se;
        G.union_set(u, v);
    }

    v32 cmpG(n+1);
    for (int i=1; i<=n; i++) cmpG[i] = G.find_set(i);

    map<int, int> roots;
    int idx = 0;
    for (int i=1; i<=n; i++)
        if (!roots.count(cmpG[i])) roots[cmpG[i]] = idx++;

    for (int i=1; i<=n; i++) cmpG[i] = roots[cmpG[i]];

    int amount = idx;
    dsu F(n);
    ll rem = 0;
    for (auto &e: eF)
    {
        int u = e.fi, v = e.se;
        if (cmpG[u] != cmpG[v]) rem++;
        else F.union_set(u, v);
    }

    vector<unordered_set<int>> root(amount);
    for (int i=1; i<=n; i++)
    {
        int rF = F.find_set(i), Gidx = cmpG[i];
        root[Gidx].insert(rF);
    }

    ll add = 0;
    for (int i=0; i<amount; i++) add += (sz(root[i])-1);

    cout << rem + add << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}