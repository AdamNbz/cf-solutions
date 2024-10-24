/*
Author : Nguyen Vo Ngoc Bao
School : University of Information Technology, VNU-HCM
*/
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

template<typename T> void ckmin(T& x, T y) {if (x>y) x = y;}
template<typename T> void ckmax(T& x, T y) {if (x<y) x = y;}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int pop_cnt(ll mask) { return __builtin_popcountll(mask); }
int ctz(ull mask) { return __builtin_ctzll(mask); }
int logOf(ull mask) { return 63 - __builtin_clzll(mask); }

const ll mod = (ll)(1e9+7);
const ll inf = (ll)(2e18);

void sol()
{
    int n; cin >> n;
    v32 a(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 0;

    for (int i = 1; i < n; ++i) 
        if (a[i] == a[i + 1]) ans++;
    
    for (int i = n / 2; i >= 1; --i) {
        int j = n - i + 1;
        int d = 0;
        v32 positions = {i - 1, i, j - 1, j};
        v32 pre, post;

        for (int pos : positions) 
            if (pos >= 1 && pos < n) pre.pb(a[pos] == a[pos + 1]);
            else pre.pb(0);

        swap(a[i], a[j]);

        for (int idx = 0; idx < sz(positions); ++idx) {
            int pos = positions[idx];
            if (pos >= 1 && pos < n) post.pb(a[pos] == a[pos + 1]);
            else post.pb(0);
            d += pre[idx] - post[idx];
        }

        if (d > 0) ans -= d;
        else swap(a[i], a[j]);
    }
    cout << ans << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}