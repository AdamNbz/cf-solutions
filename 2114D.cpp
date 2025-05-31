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
    int n; cin >> n;
    v64 x(n), y(n); for (int i=0; i<n; i++) cin >> x[i] >> y[i];

    if (n == 1)
    {
        cout << 1 << el;
        return;
    }

    v64 xx = x, yy = y;
    sort(all(xx));
    sort(all(yy));
    int cntx1 = upper_bound(all(xx), xx[0])-xx.begin(), cnty1 = upper_bound(all(yy), yy[0])-yy.begin(),
        cntxn = xx.end()-lower_bound(all(xx), xx[n-1]), cntyn = yy.end()-lower_bound(all(yy), yy[n-1]);

    ll ans = (xx[n-1]-xx[0]+1)*(yy[n-1]-yy[0]+1);
    for (int i=0; i<n; i++)
    {
        ll lX = (x[i]==xx[0] && cntx1==1 ? xx[1]:xx[0]), rX = (x[i]==xx[n-1] && cntxn==1 ? xx[n-2] : xx[n-1]),
            lY = (y[i]==yy[0] && cnty1==1 ? yy[1]:yy[0]), rY = (y[i]==yy[n-1] && cntyn==1 ? yy[n-2] : yy[n-1]);
        
        ll tmp;
        if ((rX-lX+1)*(rY-lY+1)-n+1 >= 1) tmp = (rX-lX+1)*(rY-lY+1);
        else tmp = min((rX-lX+2)*(rY-lY+1), (rX-lX+1)*(rY-lY+2));
        ckmin(ans, tmp);
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