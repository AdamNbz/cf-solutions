#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

int pop_cnt(ll mask) { return __builtin_popcountll(mask); }
int ctz(ull mask) { return __builtin_ctzll(mask); }
int logOf(ull mask) { return 63 - __builtin_clzll(mask); }

const ll mod = (ll)(1e9+7);
const ll inf = (ll)(2e18);
const ll mxN = (ll)(2e5+5);

int n;
v32 pref(mxN), suf(mxN), a(mxN);

void sol()
{
    cin >> n;

    // binary search
    for (int i=0; i<n; i++) cin >> a[i];
    int l = 0, r = n-1, ans = 0, s1 = a[0], s2 = a[n-1];
    while (l < r)
    {
        if (s1 == s2) ans = max(ans, l+1+n-r);
        if (s1 <= s2) l++, s1 += a[l];
        else r--, s2 += a[r];
    }

    //ctdl map
    // for (int i=1; i<=n; i++) cin >> a[i];
    // int ans = 0, s = accumulate(a.begin()+1, a.begin()+n+1, 0), s1 = 0;
    // map<int, int> mp;
    // for (int i=1; i<=n; i++)
    // {
    //     s1 += a[i];
    //     if (s1*2 <= s) mp[s1] = i;
    // }
    // s1 = 0;
    // for (int i=n; i>=1; i--)
    // {
    //     s1 += a[i];
    //     if (mp[s1]) ans = max(ans, mp[s1]+n-i+1);
    // }

    cout << ans << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}