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

void sol()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int q; cin >> q;
    
    vector<array<int, 26>> nxt(n+2);
    for (int i=0; i<k; i++) nxt[n][i] = n+1, nxt[n+1][i] = n+1;

    for (int i=n-1; i>=0; i--) 
    {
        for (int j=0; j<k; j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][s[i]-'a'] = i+1;
    }

    v32 dp(n+2, 0);
    dp[n+1] = 0;
    for (int i=n; i>=0; i--)
    {
        dp[i] = INT_MAX;
        for (int j=0; j<k; j++) if (nxt[i][j] == n+1) 
        {
            dp[i] = 1;
            break;
        }
        if (dp[i] != 1) 
        {
            for (int j=0; j<k; j++) ckmin(dp[i], 1+dp[nxt[i][j]]);
        }
    }

    while (q--)
    {
        int idx = 0;
        string t; cin >> t;
        for (auto c: t) 
        {
            idx = nxt[idx][c-'a'];
            if (idx == n+1) break;
        }
        cout << (idx == n+1 ? 0 : dp[idx]) << el;
    }
}

nbzzz()
{
    io();
    sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}