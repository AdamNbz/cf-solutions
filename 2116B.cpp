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

const ll mod = (ll)(998244353);
const ll inf = numeric_limits<ll>::max();

ll p2[100001];

void prec()
{
    p2[0] = 1;
    for (int i = 1; i <= 100000; i++)
        p2[i] = (p2[i-1] * 2ll) % mod;
}

void sol()
{
    int n; cin >> n;
    v64 p(n), q(n);
    for (auto &x: p) cin >> x;
    for (auto &x: q) cin >> x;

    v64 pval(n), ppos(n), qval(n), qpos(n); 
    pval[0] = p[0], ppos[0] = 0, qval[0] = q[0], qpos[0] = 0;
    for (int i=1; i<n; i++) 
    {
        if (p[i] > pval[i-1]) pval[i] = p[i], ppos[i] = i;
        else pval[i] = pval[i-1], ppos[i] = ppos[i-1];
        if (q[i] > qval[i-1]) qval[i] = q[i], qpos[i] = i;
        else qval[i] = qval[i-1], qpos[i] = qpos[i-1];
    }

    v64 ans(n, 0);
    for (int i=0; i<n; i++)
    {
        int idx1 = max(pval[i], qval[i]), idx2 = 0;
        idx2 = (pval[i] > qval[i] ? q[i-ppos[i]] : pval[i] < qval[i] ? p[i-qpos[i]] : max(p[i-qpos[i]], q[i-ppos[i]]));

        ans[i] = 1ll*(p2[idx1] + p2[idx2]) % mod;
    }

    for (auto x: ans) cout << x << " ";
    cout << el;
}

nbzzz()
{
    io();
    prec();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}