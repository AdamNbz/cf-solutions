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

int pop_cnt(ll mask) { return __builtin_popcountll(mask); }
int ctz(ull mask) { return __builtin_ctzll(mask); }
int logOf(ull mask) { return 63 - __builtin_clzll(mask); }

const ll mod = (ll)(1e9+7);
const ll inf = (ll)(2e18);
const int N = (2e5+5);

int parents[N];

int find_set(int v) {
    return (v == parents[v]) ? v : parents[v] = find_set(parents[v]);
}

void sol()
{
    int n; cin >> n;
    v32 a(n+1), ans(n+1, 0);
    memset(parents, 0, sizeof parents);
    for (int i=1; i<=n; i++) cin >> a[i], parents[i] = i;
    string s; cin >> s; s = " " + s;
    for (int i=1; i<=n; i++)
    {
        if (parents[i] != i) continue;
        ans[i] += (s[i] == '0');
        int tmp = i;
        while (tmp != a[tmp])
        {
            tmp = a[tmp];
            if (tmp == i) break;
            parents[tmp] = i;
            ans[i] += (s[tmp] == '0');
        }
    }
    for (int i=1; i<=n; i++) cout << ans[find_set(i)] << " ";
    cout << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}