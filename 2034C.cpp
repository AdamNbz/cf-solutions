/*
Author : Nguyen Vo Ngoc Bao
School : University of Information Technology, VNU-HCM
*/
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

// #ifndef ONLINE_JUDGE
// #include </Users/home/Documents/nbz_lib/debug.h>
// #else
// #define dbg(...) 
// #endif

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
    vs grid(n);
    for (auto &x: grid) cin >> x;

    vv32 bad(n, v32(m, 0));
    deque<p32> dq;
    int ans=0;

    for (int i=0; i<n; i++) 
    {
        if (grid[i][0] == 'L') bad[i][0] = 1, dq.pb({i, 0});

        if (grid[i][m-1] == 'R') bad[i][m-1] = 1, dq.pb({i, m-1});
    }

    for (int i=0; i<m; i++)
    {
        if (grid[0][i] == 'U') bad[0][i] = 1, dq.pb({0, i});

        if (grid[n-1][i] == 'D') bad[n-1][i] = 1, dq.pb({n-1, i});
    }

    while (!dq.empty())
    {
        int x = dq.front().fi, y = dq.front().se;
        dq.pop_front();

        if (x > 0 && !bad[x-1][y] && grid[x-1][y] == 'D') bad[x-1][y] = 1, dq.pb({x-1, y});

        if (x < n-1 && !bad[x+1][y] && grid[x+1][y] == 'U') bad[x+1][y] = 1, dq.pb({x+1, y});

        if (y > 0 && !bad[x][y-1] && grid[x][y-1] == 'R') bad[x][y-1] = 1, dq.pb({x, y-1});

        if (y < m-1 && !bad[x][y+1] && grid[x][y+1] == 'L') bad[x][y+1] = 1, dq.pb({x, y+1});
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (!bad[i][j] && grid[i][j] != '?') ans++;
            else if (!bad[i][j]) 
            {
                bool ok = 1;
                if (i > 0) ok &= bad[i-1][j];
                if (j > 0) ok &= bad[i][j-1];
                if (i < n-1) ok &= bad[i+1][j];
                if (j < m-1) ok &= bad[i][j+1];
                if (!ok) ans++;
            }
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