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

int pop_cnt(ll mask) { return __builtin_popcountll(mask); }
int ctz(ull mask) { return __builtin_ctzll(mask); }
int logOf(ull mask) { return 63 - __builtin_clzll(mask); }

const ll mod = (ll)(1e9+7);
const ll inf = (ll)(2e18);

void sol()
{
    int n, d, k; cin >> n >> d >> k;
    v32 cnt(n+d+2, 0);
    for (int i=0; i<k; i++)
    {
        int li, ri; cin >> li >> ri;
        int st = max(1ll, li-d+1), en = min(ri, n-d+1);
        if (st <= en)
        {
            cnt[st]++;
            cnt[en+1]--;
        }
    }

    int mx = -1, mn = k+1, bro = n+1, mother = n+1, cur = 0;
    for (int i=1; i<=n-d+1; i++)
    {
        cur += cnt[i];
        if (cur > mx || (cur == mx && i < bro)) 
        {
            mx = cur;
            bro = i;
        }
        if (cur < mn || (cur == mn && i < mother))
        {
            mn = cur;
            mother = i;
        }
    }
    cout << bro << " " << mother << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}