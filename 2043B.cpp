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
int parity(ull mask) { return __builtin_parityll(mask); }

const ll mod = (ll)(1e9+7);
const ll inf = numeric_limits<ll>::max();

void sol()
{
    int n, d; cin >> n >> d;
    cout << 1 << " ";
    auto div3 = [&](long long n, int d){
            if (n >= 3) return 1;
            return (d==3||d==6||d==9?1:0);
    };
    auto div7 = [&](long long n, int d)
    {
        if (n >= 3) return 1;
        return (d==7?1:0);
    };
    auto div9 = [&](long long n, int d)
    {
        if (n >= 6) return 1;
        if (n == 2) return (d == 9?1:0);
        if (n >= 3) return (d==3||d==6||d==9?1:0);
        return 0;
    };
    vector<int> ans;
    if (div3(n, d)) ans.push_back(3);
    if (d==5) ans.push_back(5);
    if (div7(n, d)) ans.push_back(7);
    if (div9(n, d)) ans.push_back(9);
    for (auto x: ans) cout << x << " ";
    cout << '\n';
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}