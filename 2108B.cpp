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

ll sum0(ll l)
{
    return (!l ? 0 : l == 1 ? inf : !(l&1) ? l : l+3);
}

ll sum2(ll val)
{
    if (!val) return 2;
    if (pop_cnt(val) >= 2) return val;

    for (int i=0; i<60; i++) if (!getbit(val, i)) return val + (2ll<<i);

    return inf;
}

void sol()
{
    ll n, x; cin >> n >> x;

    if (n == 1)
    {
        cout << (x ? x:-1) << el;
        return;
    } 
    if (n == 2)
    {
        cout << sum2(x) << el;
        return;
    }
    if (!x)
    {
        cout << sum0(n) << el;
        return;
    }

    ll ans = inf;
    if (n-1 != 1) ckmin(ans, 1ll*x+sum0(n-1));
    if (n-2 != 1) ckmin(ans, 1ll*sum2(x)+sum0(n-2));
    for (int i=3; i<=pop_cnt(x) && i<=n; i++)
    {
        if (n == i+1) continue;
        ckmin(ans, 1ll*x+sum0(n-i));
    }
    cout << ans << el;
}

nbzzz()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}