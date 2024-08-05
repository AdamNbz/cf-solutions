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
 
bool cmp(v32 b)
{
    int g = __gcd(b[0], b[1]);
    for (int i=1; i<sz(b)-1; i++)
    {
        int cur = __gcd(b[i], b[i+1]);
        if (cur < g) return 0;
        g = cur;
    }
    return 1;
}

void sol()
{
    int n; cin >> n;
    v32 a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    v32 b1 = a, b2 = a, b3 = a;
    int g = -1, idx = 0;
    for (int i=0; i<n-1; i++)
    {
        int cur = __gcd(a[i], a[i+1]);
        if (cur < g) 
        {
            idx = i;
            break;
        }
        g = cur;
    }
    if (g == -1) 
    {
        cout << "YES\n";
        return;
    }
    if (idx > 0) b1.erase(b1.begin() + idx - 1);
    b2.erase(b2.begin()+idx);
    if (idx < n-1) b3.erase(b3.begin()+idx+1);
    (cmp(b1) || cmp(b2) || cmp(b3)) ? cout << "YES\n" : cout << "NO\n"; 
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}