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

int calc(vp32 &a, int m)
{
    if (a.empty()) return 0;

    sort(all(a));
    int ret = 0, crrSt = a[0].fi, crrEn = a[0].se;
    for (int i=1; i<sz(a); i++)
    {
        auto &it = a[i];
        if (it.fi > crrEn)
        {
            ret += (crrEn-crrSt);
            crrSt = it.fi, crrEn = it.se;
        }
        else ckmax(crrEn, it.se);
    }

    ret += (crrEn-crrSt);
    ckmin(ret, m);
    return ret;
}

void sol()
{
    int n, m; cin >> n >> m;
    vp32 a(n);
    for (auto &x: a) cin >> x.fi >> x.se;

    int ans = 0, crrX = 0, crrY = 0;
    vp32 sqr(n);
    for (int i=0; i<n; i++)
    {
        crrX += a[i].fi;
        crrY += a[i].se;
        sqr[i] = make_pair(crrX, crrY);
    }

    for (int i=0; i<n; i++)
    {
        int x = sqr[i].fi, y = sqr[i].se;
        {
            vp32 tmp;
            for (int j=0; j<n; j++)
            {
                if (j == i) continue;
                int crx = sqr[j].fi, cry = sqr[j].se;
                if (crx <= x && x <= crx+m)
                {
                    int st = max(0, cry-y), en = min(m, (cry+m)-y);
                    if (st < en) tmp.pb(make_pair(st, en));
                }
            }
            ans += (m-calc(tmp, m));
        }

        {
            vp32 tmp;
            int eX = x+m;
            for (int j=0; j<n; j++)
            {
                if (j == i) continue;
                int crx = sqr[j].fi, cry = sqr[j].se;
                if (crx <= eX && eX <= crx+m)
                {
                    int st = max(0, cry-y), en = min(m, (cry+m)-y);
                    if (st < en) tmp.pb(make_pair(st, en));
                }
            }
            ans += (m-calc(tmp, m));
        }

        {
            vp32 tmp;
            int eY = y;
            for (int j=0; j<n; j++)
            {
                if (j == i) continue;
                int crx = sqr[j].fi, cry = sqr[j].se;
                if (cry <= eY && eY <= cry+m)
                {
                    int st = max(0, crx-x), en = min(m, (crx+m)-x);
                    if (st < en) tmp.pb(make_pair(st, en));
                }
            }
            ans += (m-calc(tmp, m));
        }

        {
            vp32 tmp;
            int eY = y+m;
            for (int j=0; j<n; j++)
            {
                if (j == i) continue;
                int crx = sqr[j].fi, cry = sqr[j].se;
                if (cry <= eY && eY <= cry+m)
                {
                    int st = max(0, crx-x), en = min(m, (crx+m)-x);
                    if (st < en) tmp.pb(make_pair(st, en));
                }
            }
            ans += (m-calc(tmp, m));
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