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
    int n; cin >> n;
    map<ll, int> cnt;
    v64 a(n), b, dist; for (auto &x: a) cin >> x, cnt[x]++;

    for (auto x: cnt) dist.pb(x.fi);

    sort(all(dist));
    for (auto x: dist)
    {
        if (cnt[x] >= 4)
        {
            cout << x << " " << x << " " << x << " " << x << el;
            return;
        }
    }
    
    for (auto x: dist) if (cnt[x] >= 2) b.pb(x);

    if (sz(b) >= 2)
    {
        int x = b[0], y = -1;
        for (auto i: b) if (i != x) 
        {
            y = i;
            break;
        }

        if (y != -1) 
        {
            cout << x << " " << x << " " << y << " " << y << el;
            return;
        }
    }

    if (b.empty())
    {
        cout << -1 << el;
        return;
    }

    ll leg = b.back(); cnt[leg] -= 2;

    ll ans1 = -1, ans2 = -1;
    int i = 0, j = 1;
    while (i < sz(dist) && j < sz(dist))
    {
        if (i == j) 
        {
            j++;
            continue;
        }

        if (!cnt[dist[i]]) 
        {
            i++;
            continue;
        }

        if (!cnt[dist[j]])
        {
            j++;
            continue;
        }

        if (i >= j) 
        {
            j = i+1;
            continue;
        }

        if (j >= sz(dist)) break;

        if (dist[j]-dist[i] < 2ll*leg)
        {
            if (dist[i]!=dist[j]) 
            {
                ans1 = dist[i], ans2 = dist[j];
                break;
            }
            j++;
        }
        else i++;
    }

    if (ans1 == -1)
    {
        cout << -1 << el;
        return;
    }

    cout << leg << " " << leg << " " << ans1 << " " << ans2 << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}