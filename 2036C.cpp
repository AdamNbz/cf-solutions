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

int cnt(const string &s, int pos)
{
    if (pos < 0 || pos+3 >= sz(s)) return 0;
    if (s[pos] == '1' && s[pos+1] == '1' && s[pos+2] == '0' && s[pos+3] == '0') return 1;
    return 0;
}

void sol()
{
    string s; cin >> s;
    ll tot = 0;
    for (int i=0; i<=sz(s)-4; i++)
        if (cnt(s, i)) tot++;

    
    int q; cin >> q;
    while (q--)
    {
        int i, v; cin >> i >> v;
        i--;
        for (int j=i-3; j<=i; j++)
            if (j >= 0 && j+3 < sz(s)) tot -= cnt(s, j);
        s[i] = (v == 1 ? '1' : '0');
        for (int j=i-3; j<=i; j++)
            if (j >= 0 && j+3 < sz(s)) tot += cnt(s, j);
        cout << (tot > 0 ? "YES" : "NO") << el;
    }
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}