#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define el '\n'
#define pb push_back
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
typedef vector<vector<int>> vv32;
typedef vector<ll> v64;
typedef vector<vector<ll>> vv64;
typedef vector<p32> vp32;
typedef vector<vector<p32>> vvp32;
typedef vector<p64> vp64;
typedef vector<vector<p64>> vvp64;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

int pop_cnt(ll mask) { return __builtin_popcountll(mask); }
int ctz(ull mask) { return __builtin_ctzll(mask); }
int logOf(ull mask) { return 63 - __builtin_clzll(mask); }

const ll mod = (ll)(1e9+7);
const ll inf = (ll)(2e18);

void sol()
{
    int n; cin >> n;
    v32 a(n);
    // int mxN = 0, idx = 0;
    // for (int i=0; i<n; i++)
    // {
    //     cin >> a[i];
    //     if (a[i] > mxN) 
    //     {
    //         mxN = a[i];
    //         idx = i;
    //     }
    // }
    // if (idx == 0 || idx == n-1) cout << mxN << el;
    // else 
    // {
    //     int ans = 0;
    //     for (int i=0; i<n; i++)
    //     {
    //         if (a[i] != mxN) ans = max(ans, a[i]);
    //     }
    //     cout << ans << el;
    // }
    for (int i=0; i<n; i++) cin >> a[i];
    int ans = 0;
    for (int i=0; i<n; i+=2) ans = max(ans, a[i]);
    cout << ans << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}