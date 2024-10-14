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
    int n, m; cin >> n >> m;
    v64 r(n), atp;
    for (int i=0; i<n; i++)
    {
        cin >> r[i];
        if (!r[i]) atp.pb(i);
    }
    ll seg = m+1;
    vv64 reqstr(seg), reqint(seg);
    v64 segind;
    segind.pb(0);
    for (auto i: atp) segind.pb(i+1);
    segind.pb(n);
    for (auto i=0; i<seg; i++)
    {
        ll s = segind[i], e = segind[i+1];
        for (auto j = s; j<e; j++)
        {
            if (r[j]>0) reqint[i].pb(r[j]);
            else if (r[j]<0) reqstr[i].pb(-r[j]);
        }
        sort(all(reqstr[i]));
        sort(all(reqint[i]));
    }

    vv64 dp(m+2, v64(m+2, -1));
    dp[0][0] = 0ll;
    for (auto i=0; i<=m; i++)
    {
        for (int j=0; j<=i; j++)
        {
            if (dp[i][j]==-1) continue;
            ll intlvl = i-j, tot=dp[i][j], segidx=i;
            auto str = upper_bound(all(reqstr[segidx]), j)-reqstr[segidx].begin();
            auto intel = upper_bound(all(reqint[segidx]), intlvl)-reqint[segidx].begin();
            tot += (str+intel);
            if (i < m)
            {
                if (dp[i+1][j] < tot) dp[i+1][j] = tot;
                if (dp[i+1][j+1] < tot) dp[i+1][j+1] = tot;
            }
            else dp[i][j] = tot;
        }
    }

    ll ans = 0;
    for (auto i=0; i<=m; i++) ans = max(ans, dp[m][i]);
    cout << ans;
}

int32_t main()
{
    io();
    sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}