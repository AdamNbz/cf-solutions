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

struct VecHash 
{
    size_t operator()(const v64 &v) const 
    {
        static const ll base = 1315423917LL;
        ll h = 0;
        for (auto &x : v) h ^= hash<ll>()(x) + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
        return (size_t)h;
    }
    bool operator()(const v64 &a, const v64 &b) const 
    {
        return a == b;
    }
};

ll calc(const v64 &a, unordered_map<v64, ll, VecHash> &m)
{
    auto it = m.find(a);
    if (it != m.end()) return it->se;

    ll crr = accumulate(all(a), 0ll), ret = crr;
    int n = sz(a);
    if (n > 1)
    {
        v64 diffLeft(n-1);
        for (int i=0; i<n-1; i++) diffLeft[i] = a[i+1]-a[i];
        ckmax(ret, calc(diffLeft, m));
        v64 b(a.rbegin(), a.rend()), diffRight(n-1);
        for (int i=0; i<n-1; i++) diffRight[i] = b[i+1]-b[i];
        ckmax(ret, calc(diffRight, m));
    }
    m[a] = ret;
    return ret;
}

void sol()
{
    int n; cin >> n;
    v64 a(n); for (auto &x: a) cin >> x;

    unordered_map<v64, ll, VecHash> memory_erase;
    cout << calc(a, memory_erase) << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}