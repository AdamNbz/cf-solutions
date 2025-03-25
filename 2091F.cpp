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

const ll mod = 998244353;
const ll inf = numeric_limits<ll>::max();

void sol()
{
    ll n, m, d; cin >> n >> m >> d;
    vs a(n); for (auto &x: a) cin >> x;

    vv64 b(n);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (a[i][j] == 'X') b[i].pb(j);
    
    for (int i=0; i<n; i++) if (b[i].empty())
    {
        cout << 0 << el;
        return;
    }

    vv64 dp(n, v64(m, 0));
    int h = sqrt(d*d-1);

    for (auto x: b[n-1])
    {
        int l = x-d, r = x+d;
        int itl = lower_bound(all(b[n-1]), l)-b[n-1].begin();
        int itr = upper_bound(all(b[n-1]), r)-b[n-1].begin();
        dp[n-1][x] = (itr-itl)%mod;
    }

    for (int i=n-2; i>=0; i--)
    {
        v64 pref(m+1, 0), znadp = dp[i+1];
        for (int j=0; j<m; j++) pref[j+1] = (pref[j]+znadp[j])%mod;

        map<ll, int> mp;
        for (auto x: b[i]) mp[x] = (pref[min(m, h+x+1)]-pref[max(0ll, x-h)]+mod)%mod;

        v64 pref2(sz(b[i])+1, 0), c;
        for (auto x: b[i]) c.pb(mp[x]);
        for (int j=0; j<sz(c); j++) pref2[j+1] = (pref2[j]+c[j])%mod;

        for (int j=0; j<sz(b[i]); j++)
        {
            int x = b[i][j], l = x-d, r = x+d;
            int itl = lower_bound(all(b[i]), l)-b[i].begin();
            int itr = upper_bound(all(b[i]), r)-b[i].begin();
            dp[i][x] = (pref2[itr]-pref2[itl]+mod)%mod;
        }
    }

    ll ans = 0;
    for (auto x: b[0]) ans = (ans+dp[0][x])%mod;
    cout << ans << el;
}

nbzzz()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}