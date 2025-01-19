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
    int n, m; cin >> n >> m;
    vv64 a(n, v64(m));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];

    v64 cards; cards.reserve(n*m);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cards.pb(a[i][j]);
        }
    }
    sort(all(cards));

    static int check[4001];
    for (int i=0; i<n*m; i++) check[cards[i]] = i+1;

    for (int i=0; i<n; i++) sort(all(a[i]));

    v32 idx(n, -1), taken(n+1, -1);
    bool ok = 1;

    for (int i=0; i<n; i++)
    {
        int pos = check[a[i][0]];
        for (int j=1; j<m; j++)
        {
            if (pos+(j*n) != check[a[i][j]])
            {
                ok = 0;
                break;
            }
        }

        if (pos < 1 || pos > n) ok = 0;
        if (!ok) break;

        if (taken[pos] != -1) 
        {
            ok = 0;
            break;
        }

        taken[pos] = i;
    }

    if (!ok) 
    {
        cout << -1 << el;
        return;
    }

    v32 p(n);
    for (int i=1; i<=n; i++) p[i-1] = taken[i]+1;

    for (auto x: p) cout << x << " ";
    cout << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}