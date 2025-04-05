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

void si(int *a, int *b)
{
    int x = *a;
    *a = *b;
    *b = x;
}

void sol()
{
    int n; cin >> n;
    v32 a(n+1), b(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];

    v32 posiA(n+1);
    for (int i=1; i<=n; i++) posiA[a[i]] = i;
    int cnt=0, idx=-1;
    for (int i=1; i<=n; i++) if (a[i] == b[i]) cnt++, idx = i;

    if (!(n%2)) 
    {
        if (cnt != 0) 
        {
            cout << -1 << el;
            return;
        }
    }
    else
    {
        if (cnt != 1) 
        {
            cout << -1 << el;
            return;
        }
    }

    vb vis(n+1);
    int pcnt = 0, sz = n/2+1;
    v32 l(sz), r(sz);

    bool ok = 1;
    for (int i=1; i<=n; i++)
    {
        if (a[i] == b[i]) continue;
        if (vis[i]) continue;
        int j = posiA[b[i]];
        if (j == i) 
        {
            ok = 0;
            break;
        }
        if (b[j] != a[i])
        {
            ok = 0;
            break;
        }
        int p = i, q = j;
        if (p > q) swap(p, q);
        l[pcnt] = p, r[pcnt++] = q;
        vis[i] = 1, vis[j] = 1;
    }
    if ((pcnt<<1) != (n-(n%2?1:0))) ok = 0;

    if (!ok) 
    {
        cout << -1 << el;
        return;
    }

    v32 sigma(n+1);
    int li = 1, r1 = n;
    for (int i=0; i<pcnt; i++) sigma[li++] = l[i], sigma[r1--] = r[i];
    if (n%2) sigma[(n+1)/2] = idx;

    v32 crr(n+1), pos(n+1);
    for (int i=1; i<=n; i++) crr[i] = i, pos[i] = i;

    vp32 ans(n+1);
    int szz = 0;
    for (int i=1; i<=n; i++)
    {
        if (crr[i] != sigma[i])
        {
            int j = pos[sigma[i]];
            si(&crr[i], &crr[j]);
            pos[crr[i]] = i, pos[crr[j]] = j;
            ans[szz++] = {i, j};
        }
    }

    cout << szz << el;
    for (int i=0; i<szz; i++) cout << ans[i].fi << " " << ans[i].se << el;
}

nbzzz()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}