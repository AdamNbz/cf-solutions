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

ll pop_cnt(ll mask) { return __builtin_popcountll(mask); }
ll ctz(ull mask) { return __builtin_ctzll(mask); }
ll logOf(ull mask) { return 63 - __builtin_clzll(mask); }
ll parity(ull mask) { return __builtin_parityll(mask); }

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

struct node
{
    ll cst;
    int idx, w;
    bool operator>(node const &other) const
    { 
        return cst > other.cst;
    }
};

void sol()
{
    int n; ll k; cin >> n >> k;
    v64 a(n); for (auto &x: a) cin >> x;

    ll cnt = 0;
    for (auto x: a) cnt += pop_cnt(x);
    
    priority_queue<node, vector<node>, greater<>> pq;
    for (int i=0; i<n; i++)
    {
        ll x = a[i];
        int crr_pc = pop_cnt(x);
        int l = (!x ? x : logOf(x)+1);
        
        v64 lft(l, 0), bit(l, 0), zro;
        for (int j=0; j<l; j++) bit[j] = getbit(x, j);
        int cnt = 0;
        for (int j=l-1; j>=0; j--) 
        {
            lft[j] = cnt;
            if (bit[j]) cnt++;
        }
        for (int j=0; j<l; j++) if (!bit[j]) zro.pb(j);

        ll prv = 0;
        int j=1;
        while (1)
        {
            int w = crr_pc + j;
            if (w >= 64) break;
            ll best = inf;
            if (mask(w)-1 >= x) best = mask(w)-1;

            for (auto u: zro)
            {
                int pref = lft[u];
                if (pref+1 <= w && w <= pref+1+u)
                {
                    int cnt1 = w-pref-1;
                    ll R = (x>>(u+1))<<(u+1), m = mask(u), L = (mask(cnt1)-1);
                    if (L+R+m >= x && L+R+m < best) best = L+R+m;
                }
            }

            if (best == inf) break;
            if (best-x > k) break;

            ll dlta = best-x-prv;
            pq.push({dlta, i, j});
            prv = best-x;
            j++;
        }
    }

    ll cnt1 = 0;
    while (!pq.empty())
    {
        auto crr = pq.top(); pq.pop();
        if (crr.cst > k) break;
        k -= crr.cst;
        cnt1++;
    }

    cout << cnt + cnt1 << el;
}

nbzzz()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}