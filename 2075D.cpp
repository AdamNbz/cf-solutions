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

vv64 dp;
vector<array<ll, 3>> comb;

void sol()
{
    ll x, y; cin >> x >> y;

    if (x == y) cout << 0 << el;
    else
    {
        ll ans = inf;
        for (auto i: comb) if ((x>>i[0]) == (y>>i[1])) ckmin(ans, i[2]);
        cout << ans << el;
    }
}

nbzzz()
{
    io();

    dp.resize(61, v64(61, inf));
    dp[0][0] = 0;
    for (int i=0; i<61; i++)
    {
        vv64 nxt = dp;
        for (int j=0; j<61; j++)
        {
            for (int k=0; k<61; k++)
            {
                if (dp[j][k] == inf) continue;

                if (i+j < 61) ckmin(nxt[i+j][k], dp[j][k] + mask(i));
                if (i+k < 61) ckmin(nxt[j][i+k], dp[j][k] + mask(i));
            }
        }
        dp = nxt;
    }

    for (int i=0; i<61; i++) for (int j=0; j<61; j++) if (dp[i][j] != inf) comb.pb({i, j, dp[i][j]});

    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}