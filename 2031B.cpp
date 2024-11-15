/*
Author : Nguyen Vo Ngoc Bao
School : University of Information Technology, VNU-HCM
*/
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#ifndef ONLINE_JUDGE
#include </Users/home/Documents/nbz_lib/debug.h>
#else
#define dbg(...) 
#endif

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
    v32 a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    if (n<3)
    {
        cout << "YES" << el;
        return;
    }
    v32 pos(n+1);
    for (int i=1; i<=n; i++) pos[a[i]] = i;
    v32 leftmx(n+1, 0), rightmn(n+2, INT_MAX);
    for (int i=1; i<=n; i++) leftmx[i] = max(leftmx[i-1], pos[i]);
    for (int i=n; i>=1; i--) rightmn[i] = min(rightmn[i+1], pos[i]);

    bool ok = 1;
    for (int i=1; i<=n; i++)
    {
        int crr = pos[i];
        if (i-2 >= 1)
        {
            int leftend = i-2;
            if (leftend >= 1)
            {
                int mxleft = leftmx[leftend];
                if (mxleft >= crr) 
                {
                    ok = 0;
                    break;
                }
            }
        }
        if (i+2 <= n)
        {
            int rightstart = i+2;
            if (rightstart <= n)
            {
                int mnright = rightmn[rightstart];
                if (mnright <= crr) 
                {
                    ok = 0;
                    break;
                }
            }
        }
    }
    cout << (ok ? "YES" : "NO") << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}