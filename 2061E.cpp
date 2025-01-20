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
int parity(ull mask) { return __builtin_parityll(mask); }

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

void sol()
{
    int n, m, k; cin >> n >> m >> k;

    v64 a(n); for (auto &x: a) cin >> x;
    v64 b(m); for (auto &x: b) cin >> x;

    ll tot = mask(m), fullmask = mask(30)-1;
    v64 sub(tot), cost(tot, 0);

    for (int i=0; i<tot; i++)
    {
        ll val = fullmask, cst = 0;
        for (int j=0; j<m; j++) if (getbit(i, j)) val &= b[j], cst++;
        sub[i] = val, cost[i] = cst;
    }

    ll sumofA = accumulate(all(a), 0ll);
    v64 inc;
    inc.reserve(1ll*n*m);
    for (int i=0; i<n; i++)
    {
        static v64 best; best.assign(m+1, -1);
        best[0] = 0;

        for (int j=1; j<tot; j++)
        {
            int cst = cost[j];
            if (cst > m) continue;
            ll val = a[i] & sub[j], imp = a[i]-val;
            ckmax(best[cst], imp);
        }

        for (int j=0; j<=m; j++) if (best[j] < 0) best[j] = 0;

        for (int j=1; j<=m; j++)
        {
            ll diff = best[j]-best[j-1];
            if (diff > 0) inc.pb(diff);
        }
    }
    sort(all(inc), greater<ll>());

    ll sumofImp = 0;
    for (int i=0; i<sz(inc) && k>0; i++)
    {
        ll val = inc[i];
        if (val <= 0) break;
        sumofImp += val;
        k--;
    }

    cout << sumofA - sumofImp << el;
    inc.clear();
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}