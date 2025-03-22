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

int mex(v32 a, int l, int r)
{
    vb pre(4, 0);
    for (int i=l; i<=r; i++) if (a[i] < 4) pre[a[i]] = 1;
    for (int i=0; i<4; i++) if (!pre[i]) return i;
    return 4;
}

void sol()
{
    int n; cin >> n;
    v32 a(n); for (auto &x: a) cin >> x;

    vp32 ans;
    while (sz(a) > 3)
    {
        bool check0 = 0;
        for (auto x: a) if (!x)
        {
            check0 = 1;
            break;
        }
        if (check0)
        {
            int pos = 0;
            for (int i=0; i<sz(a); i++) if (!a[i])
            {
                pos = i;
                break;
            }
            if (!pos)
            {
                int m = mex(a, 0, 1);
                ans.pb({1, 2});
                v32 newa;
                newa.pb(m);
                for (int i=2; i<sz(a); i++) newa.pb(a[i]);
                a = newa;
            }
            else
            {
                int m = mex(a, pos-1, pos);
                ans.pb({pos, pos+1});
                v32 newa;
                for (int i=0; i<pos-1; i++) newa.pb(a[i]);
                newa.pb(m);
                for (int i=pos+1; i<sz(a); i++) newa.pb(a[i]);
                a = newa;
            }
        }
        else
        {
            int m = mex(a, 0, sz(a)-1);
            ans.pb({1, sz(a)});
            a = v32(1, m);
            break;
        }
        if (sz(a) == 3)
        {
            int m = mex(a, 0, 1);
            if (m != 0 && a[2] != 0)
            {
                ans.pb({1, 2});
                v32 newa;
                newa.pb(m);
                newa.pb(a[2]);
                a = newa;
            }
            else
            {
                int p = mex(a, 1, 2);
                if (p != 0 && a[0] != 0)
                {
                    ans.pb({2, 3});
                    v32 newa;
                    newa.pb(a[0]);
                    newa.pb(p);
                    a = newa;
                }
                else
                {
                    ans.pb({1, 3});
                    int q = mex(a, 0, 2);
                    a = v32(1, q);
                }
            }
        }
        if (sz(a) == 2)
        {
            int m = mex(a, 0, 1);
            ans.pb({1, 2});
            a = v32(1, m);
        }
    }

    cout << sz(ans) << el;
    for (auto x: ans) cout << x.fi << " " << x.se << el;
}

nbzzz()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}