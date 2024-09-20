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
#define int long long

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

void sol()
{
    int n; cin >> n;
    v64 a(n+20);
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(a.begin()+1, a.begin()+1+n);
    v64 b;
    for (int i=2; i<=n; i++) b.pb(a[i]);
    ll g = a[1], ans = a[1];
    while (1)
    {
        v64 c;
        int idx = -1, mn = g;
        for (int i=0; i<sz(b); i++)
        {
            int cur = gcd(g, b[i]);
            if (cur < mn)
            {
                mn = cur;
                idx = i;
            }
        }
        if (idx == -1)
        {
            ans += g*sz(b);
            break;
        }
        else
        {
            g = mn;
            for (int i=0; i<sz(b); i++)
                if (i != idx) c.pb(b[i]);
            ans += g;
            b = c;
        }
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