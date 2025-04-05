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

ll Gcd(ll a, ll b)
{
    while (b) 
    {
        ll tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

void sol()
{
    int n; cin >> n;
    v64 a(n); for (auto &x: a) cin >> x;

    ll mn = *min_element(all(a));
    int cnt = 0, sz = 0;
    for (auto x: a) cnt += (x==mn);
    
    v32 same(n);
    v64 div(n);
    for (int i=0; i<n; i++) if (!(a[i]%mn)) div[sz] = a[i]/mn, same[sz++] = (a[i]==mn);
    
    ll gcd = 0;
    for (int i=0; i<sz; i++) gcd = (!i ? div[i] : Gcd(gcd, div[i]));
    if (gcd != 1 || sz < 2) 
    {
        cout << "NO" << el;
        return;
    }

    v64 pref(sz), suf(sz);
    pref[0] = div[0];
    suf[sz-1] = div[sz-1];
    for (int i=1; i<sz; i++) pref[i] = Gcd(pref[i-1], div[i]);
    for (int i=sz-2; i>=0; i--) suf[i] = Gcd(suf[i+1], div[i]);

    bool ans = 0;
    for (int i=0; i<sz; i++)
    {
        if (same[i]) 
        {
            ll missing = 0;
            if (i > 0) missing = pref[i-1];
            if (i < sz-1) missing = (!missing?suf[i+1]:Gcd(missing, suf[i+1]));
            if (missing == 1) 
            {
                ans = 1;
                break;
            }
        }
    }

    cout << (ans ? "YES" : "NO") << el;
}

nbzzz()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}