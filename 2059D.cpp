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
      #define dbg(...)
   #endif
#else
   #define dbg(...) 
#endif

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

void sol()
{
    int n, s1, s2; cin >> n >> s1 >> s2;
    s1--, s2--;

    int m1, m2;
    cin >> m1;
    vv32 g1(n);
    for (int i=0; i<m1; i++)
    {
        int u, v; cin >> u >> v; u--, v--;
        g1[u].pb(v);
        g1[v].pb(u);
    }
    
    cin >> m2;
    vv32 g2(n);
    for (int i=0; i<m2; i++)
    {
        int u, v; cin >> u >> v; u--, v--;
        g2[u].pb(v);
        g2[v].pb(u);
    }

    vb ok(n, 0);
    for (int i=0; i<n; i++)
    {
        unordered_set<int> skibidi;
        for (auto nb: g1[i]) skibidi.insert(nb);
        for (auto nb: g2[i]) 
        {
            if (skibidi.count(nb))
            {
                ok[i] = 1;
                break;
            }
        }
    }

    v64 dist(n*n, (1ll<<60));
    auto idx = [&](int v1, int v2) -> int
    {
        return v1*n+v2;
    };

    int st = idx(s1, s2);
    dist[st] = 0;
    priority_queue<p64, vp64, greater<p64>> pq;
    pq.push({0, st});

    ll ans = -1;
    while(!pq.empty())
    {
        auto x = pq.top(); pq.pop();
        if (x.fi != dist[x.se]) continue;

        int v1 = x.se/n, v2 = x.se%n;
        if (v1 == v2 && ok[v1])
        {
            ans = x.fi;
            break;
        }

        for (auto u1: g1[v1])
        {
            for (auto u2: g2[v2])
            {
                int nxt = idx(u1, u2), cost = abs(u1-u2);
                if (dist[nxt] > x.fi + cost)
                {
                    dist[nxt] = x.fi+cost;
                    pq.push({dist[nxt], nxt});
                }
            }
        }
    }

    cout << ans << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}