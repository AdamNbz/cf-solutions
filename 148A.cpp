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
 
const ll mod = (ll)(1e9+7);
const ll inf = (ll)(2e18);
 
void sol()
{
    int k, l, m, n, d; cin >> k >> l >> m >> n >> d;
    int ans = d;
    for (int i=1; i<=d; i++) ans -= (i%k && i%l && i%m && i%n ? 1 : 0);
    (k == 1 || l == 1 || m == 1 || n == 1) ? cout << d : cout << ans;
    cout << el;
}

int32_t main()
{
   io();
   //int t; cin >> t;
   /*while (t--)*/ sol();
   cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}