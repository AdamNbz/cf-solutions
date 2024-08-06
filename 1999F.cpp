#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define el '\n'
#define pb push_back
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
typedef vector<vector<int>> vv32;
typedef vector<ll> v64;
typedef vector<vector<ll>> vv64;
typedef vector<p32> vp32;
typedef vector<vector<p32>> vvp32;
typedef vector<p64> vp64;
typedef vector<vector<p64>> vvp64;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

int pop_cnt(ll mask) { return __builtin_popcountll(mask); }
int ctz(ull mask) { return __builtin_ctzll(mask); }
int logOf(ull mask) { return 63 - __builtin_clzll(mask); }

const ll mod = (ll)(1e9+7);
const ll inf = (ll)(2e18);
const int N = 200200;

ll fact[N], inv[N];

ll power(ll a, ll k) {
	ll ret = 1;
	for(; k; k >>= 1, a = a * a % mod)
		if(k & 1) ret = ret * a % mod;
	return ret;
}

ll C(int n, int k) {
	if(n < k || k < 0) return 0;
	return fact[n] * inv[n - k] % mod * inv[k] % mod;
}

void sol()
{
    int n, k; cin >> n >> k;
    v32 a(n), cnt(2);
    for (int i=0; i<n; i++) 
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll ans = 0;
    for (int i=0; i<=k/2; i++) 
    {
        ans += C(cnt[0], i) * C(cnt[1], k-i) % mod;
        ans %= mod;
    }
    cout << ans << el;
}

int32_t main()
{
    io();
    fact[0] = inv[0] = 1;
	for(int i = 1; i <= 200000; ++i) {
		fact[i] = fact[i - 1] * i % mod;
		inv[i] = power(fact[i], mod - 2);
	}
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}