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
const int mxN = 5e1;

void sol()
{
    int n, k; cin >> n >> k;
    v64 a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vv64 dp(n+1);
    dp[0].pb(0);
    for (int i=1; i<=n; i++)
    {
        int sel = min(i, k);
        dp[i].resize(sel+1, -1000000000000000000LL);
        for (int j=0; j<sz(dp[i-1]); j++) ckmax(dp[i][j], dp[i-1][j]);
        for (int j=1; j<=sel; j++)
            if (j-1 < sz(dp[i-1]) && dp[i-1][j-1] != -1000000000000000000LL) ckmax(dp[i][j], dp[i-1][j-1] + a[i-1]);
    }

    vv64 dp1(n+1);
    dp1[n].pb(0);
    for (int i=n-1; i>=0; i--)
    {
        int sel = min(n-i, k);
        dp1[i].resize(sel+1, -1000000000000000000LL);
        for (int j=0; j<sz(dp1[i+1]); j++) ckmax(dp1[i][j], dp1[i+1][j]);
        for (int j=1; j<=sel; j++) 
            if (j-1 < sz(dp1[i+1]) && dp1[i+1][j-1] != -1000000000000000000LL) ckmax(dp1[i][j], dp1[i+1][j-1] + a[i]);
    }

    ll ans = 0;
    for (int i=0; i<n; i++)
    {
        ll crr = -1000000000000000000LL;
        if (!i) crr = a[i] + dp1[1][k];
        else if (i == n-1) crr = a[n-1] + dp[n-1][k];
        else
        {
            int lf = i, rg = n-i-1;
            for (int j=1; j<=min(k-1, lf); j++) 
            {
                int e = k-j;
                if (e < 1 || e > rg) continue;

                if (j < sz(dp[i]) && e < sz(dp1[i+1])) 
                {
                    if (dp[i][j] == -1000000000000000000LL || dp1[i+1][e] == -1000000000000000000LL) continue;
                    ckmax(crr, a[i] + dp[i][j] + dp1[i+1][e]);
                }
            }
        }
        ckmax(ans, crr);
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