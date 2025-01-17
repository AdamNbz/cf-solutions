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

ll calc_cnt(ll n) {
    if (n % 2 == 0) 
    {
        long long p = n / 2;
        return p * (p + 1);
    } 
    else 
    {
        long long p = (n - 1) / 2;
        return (p + 1) * (p + 1);
    }
}

bool chk(const v32 &freq, int len) {
    int k = len / 2;
    static int prefixFreq[11];
    prefixFreq[0] = 0;
    for(int v = 1; v <= 10; v++)
        prefixFreq[v] = prefixFreq[v-1] + freq[v-1]; 

    for(int x = 1; x <= 10; x++)
    {
        int cLess = prefixFreq[x-1], cEq = freq[x-1];
        if (cLess <= k - 1 && (cLess + cEq) >= (k + 1)) return true;
    }
    return false;
}

void sol()
{
    int n; cin >> n;
    v32 a(n);
    for (auto &x: a) cin >> x;

    ll oddcnt = calc_cnt(n), totsub = 1ll*n*(n+1)/2, even = totsub - oddcnt, good = 0;
    int mx = min(n, 20);
    v32 f(10, 0);
    for (int i=2; i<=mx; i+=2)
    {
        fill(all(f), 0);
        for (int j=0; j<i; j++) f[a[j]-1]++;
        if (chk(f, i)) good++;

        for (int j=1; j+i-1<n; j++)
        {
            int preval = a[j-1], val = a[j+i-1];
            f[preval-1]--, f[val-1]++;
            if (chk(f, i)) good++;
        }
    }

    ll cnt = 0;
    for (int i=2; i<=mx; i+=2) cnt += (n-i+1);

    good += (even-cnt);
    cout << oddcnt+good << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}