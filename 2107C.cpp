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

const ll fills = (ll)(-1e18);

void sol()
{
    int n; ll k; cin >> n >> k;
    string s; cin >> s;
    v32 a(n+2, 0); for (int i=1; i<=n; i++) cin >> a[i];

    v64 pref(n+2, 0), suf(n+2, 0);
    ll mx = 0, idx_zero = -1;
    for (int i=1; i<=n; i++)
    {
        if (s[i-1] == '1') pref[i] = max(0ll, pref[i-1]+a[i]), ckmax(mx, pref[i]);
        else 
        {
            pref[i] = 0;
            if (idx_zero < 0) idx_zero = i;
        }
    }

    for (int i=n; i>=1; i--)
        if (s[i-1] == '1') suf[i] = max(0ll, suf[i+1]+a[i]);
        else suf[i] = 0;

    if (mx > k) 
    {
        cout << "NO" << el;
        return;
    }

    if (idx_zero < 0)
    {
        if (mx == k) 
        {
            cout << "YES" << el;
            for (int i=1; i<=n; i++) cout << a[i] << " ";
            cout << el;
        }
        else cout << "NO" << el;
        return;
    }

    ll need = k-(pref[idx_zero-1]+suf[idx_zero+1]);
    cout << "YES" << el;
    for (int i=1; i<=n; i++) cout << (s[i-1] == '1' ? a[i] : i == idx_zero ? need : fills) << " ";
    cout << el;
}

nbzzz()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}