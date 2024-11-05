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
    int n, k, q; cin >> n >> k >> q;
    vv32 a(n+1, v32(k+1)), b(n+1, v32(k+1));
    vector<vp32> regval(k+1);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=k; j++)
        {
            cin >> a[i][j];
            if (i==1) b[i][j] = a[i][j];
            else b[i][j] = b[i-1][j] | a[i][j];
        }
    }

    for (int i=1; i<=k; i++)
    {
        vp32& ch = regval[i];
        ch.emplace_back(b[1][i], 1);
        for (int j=2; j<=n; j++)
            if (b[j][i] != b[j-1][i]) ch.emplace_back(b[j][i], j);
    }

    while (q--)
    {
        int m; cin >> m;
        int mnlast = n, mxfirst = 1;
        for (int i=0; i<m; i++)
        {
            int r;
            string o;
            int c;
            cin >> r >> o >> c;
            vp32& chtmp = regval[r];
            if (o == "<")
            {
                auto it = lower_bound(all(chtmp), make_pair(c, 0));
                int last;
                if (it == chtmp.begin())
                {
                    if (chtmp[0].fi >= c)last = chtmp[0].se-1;
                    else last=n;
                }
                else
                {
                    it--;
                    last = n;
                    if (it->fi < c)
                    {
                        if (next(it) != chtmp.end()) last = next(it)->se-1;
                        else last = n;
                    }
                    else last = it->se-1;
                }
                ckmin(mnlast, last);
            }
            else
            {
                auto it = upper_bound(all(chtmp), make_pair(c, n+1));
                int first;
                if (it == chtmp.end()) first = n+1;
                else first = it->se;
                ckmax(mxfirst, first);
            }
        }
        cout << (mnlast >= mxfirst ? mxfirst : -1) << el;
    }
}

int32_t main()
{
    io();
    sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}