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

bool check7(ll n)
{
    while (n > 0)
    {
        if (n%10 == 7) return 1;
        n/=10;
    }
    return 0;
}

void sol()
{
    ll n; cin >> n;
    if (check7(n))
    {
        cout << 0 << el;
        return;
    }
    
    int ans = -1;
    for (int i=1; i<31; i++)
    {
        ll crr = n-i;
        v32 dg(20, 0);
        int sz = 0;
        if (!crr) dg[sz++] = 0;
        else while (crr > 0) dg[sz++] = crr%10, crr/=10;

        int l = max(12, sz), mx = 40;
        int dp[32][42], dp2[32][42];
        memset(dp, 0, sizeof dp);
        memset(dp2, 0, sizeof dp2);

        dp[i][0] = 1;
        for (int pos=0; pos<l; pos++)
        {
            for (int j=0; j<=i; j++)
                for (int k=0; k<mx; k++)
                    dp2[j][k] = 0;
            int d = (pos<sz?dg[pos]:0);
            for (int rm=0; rm<=i; rm++)
            {
                for (int mask=0; mask<mx; mask++)
                {
                    int cur = dp[rm][mask];
                    if (!cur) continue;
                    for (int j=0; j<=rm; j++)
                    {
                        int tot = d+mask+j, newdg = tot%10, newmask = tot/10;
                        if (newmask >= mx) continue;
                        int newrm = rm-j, newcur = cur;
                        if (newdg == 7) newcur |= 2;
                        dp2[newrm][newmask] |= newcur;
                    }
                }
            }

            for (int j=0; j<=i; j++)
                for (int k=0; k<mx; k++)
                    dp[j][k] = dp2[j][k];
        }
        if ((dp[0][0]&2) != 0)
        {
            ans = i;
            break;
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