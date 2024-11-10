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


void sol()
{
    ll n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    ll crrX = 0, crrY = 0;
    v64 posX(n+1, 0), posY(n+1, 0);
    for (int i=0; i<n; i++)
    {
        int dx=0, dy=0;
        if (s[i] == 'N') dy = 1;
        else if (s[i] == 'S') dy = -1;
        else if (s[i] == 'E') dx = 1;
        else dx = -1;
        crrX += dx, crrY += dy;
        posX[i+1] = posX[i] + dx, posY[i+1] = posY[i] + dy;
    }

    for (int i=0; i<n; i++)
    {
        ll xi = posX[i+1], yi = posY[i+1], dx = crrX, dy = crrY;
        if (!dx && !dy)
        {
            if (xi == a && yi == b) 
            {
                cout << "YES" << el;
                return;
            }
        }

        bool ok = 1;
        ll kx = 0, ky = 0;
        if (dx) 
        {
            if ((a-xi)%dx) ok = 0;
            else
            {
                kx = (a-xi)/dx;
                if (kx < 0) ok = 0;
            }
        }
        if (dy)
        {
            if ((b-yi)%dy) ok = 0;
            else
            {
                ky = (b-yi)/dy;
                if (ky < 0) ok = 0;
            }
        }
        if (dx && dy)
        {
            if (kx != ky) ok = 0;
        }
        else if (!dx && !dy)
        {
            if (xi != a || yi != b) ok = 0;
        }
        else if (!dx)
        {
            if (xi != a) ok = 0;
        }
        else if (!dy)
        {
            if (yi != b) ok = 0;
        }
        if (ok)
        {
            cout << "YES" << el;
            return;
        }
    }
    cout << "NO" << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}