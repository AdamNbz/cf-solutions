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

#define int long long

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

void compute_pisano_period(int k, int &pisano_period, v32 &positions) {
    if (k == 1) {
        pisano_period = 1;
        positions.push_back(1);
        return;
    }
    int f_prev = 1 % k;
    int f_cur = 1 % k;
    positions.clear();
    int max_period = 6 * k;
    for (int i = 3; i <= max_period; ++i) {
        int f_next = (f_prev + f_cur) % k;
        if (f_next == 0) {
            positions.pb(i);
        }
        f_prev = f_cur;
        f_cur = f_next;
        if (f_prev == 1 % k && f_cur == 1 % k && i > 3) {
            pisano_period = i - 2;
            return;
        }
    }
    pisano_period = max_period;
}

vp64 q;
set<ll> uni;
void sol()
{
    map<ll, v64> pos;
    map<ll, ll> pisano;
    for (auto k: uni)
    {
        ll pis = 0;
        v64 positions;
        compute_pisano_period(k, pis, positions);
        if (positions.empty()) positions.pb(-1);
        pisano[k] = pis;
        pos[k] = positions;
    }
    for (auto &[n, k]: q)
    {
        v64& positions = pos[k];
        ll len = pisano[k];
        ll c = sz(positions);

        if (positions[0] == -1)
        {
            cout << "-1" << el;
            continue;
        }
        ll full = (n-1)/c, rem = (n-1)%c;
        ll ans = (full*len)%mod;
        ans = (ans+positions[rem])%mod;
        cout << ans%mod << el;
    }
}

int32_t main()
{
    io();
    int t; cin >> t;
    q.resize(t);
    for (int i=0; i<t; i++)
    {
        ll n;
        int k;
        cin >> n >> k;
        q[i] = {n, 1ll*k};
        uni.insert(1ll*k);
    }
    sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}