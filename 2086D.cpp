/*
Author : Nguyen Vo Ngoc Bao
School : University of Information Technology, VNU-HCM
*/
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#ifndef ONLINE_JUDGE
   #if defined(__APPLE__)
      #include </Users/home/Documents/nbz_lib/debug.h>
   #elif defined(_WIN32) || defined(_WIN64)
      #include <C:/Users/Admin/OneDrive/Documents/nbz_lib/debug.h>
   #endif
#else
   #define dbg(...) 
#endif

#define nbzzz signed main
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

const ll mod = 998244353;
const ll inf = numeric_limits<ll>::max();

template <int M>
struct ModInt
{
    static constexpr int MOD = M;
    static_assert(M > 0);

private:
    int val;

    static int invmod(int a, int m)
    {
        a %= m;
        assert(a);
        return (a == 1 ? 1 : int(m - ll(invmod(m, a)) * ll(m) / a));
    }

public:
    ModInt() : val(0) {}
    ModInt(int64_t x) : val(int(x % MOD))
    {
        if (val < 0)
            val += MOD;
    }
    explicit operator int() const { return val; }
    ModInt &operator++()
    {
        if (++val == MOD)
            val = 0;
        return *this;
    }
    ModInt &operator--()
    {
        if (--val < 0)
            val += MOD;
        return *this;
    }
    ModInt &operator+=(const ModInt &other)
    {
        val += other.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    ModInt &operator-=(const ModInt &other)
    {
        val -= other.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    ModInt &operator*=(const ModInt &other)
    {
        val = int(ll(val) * ll(other.val) % MOD);
        return *this;
    }
    ModInt &operator/=(const ModInt &other) { return *this *= ModInt(other.val, nullptr); }
    ModInt operator+(const ModInt &other) const { return ModInt(*this) += other; }
    ModInt operator-(const ModInt &other) const { return ModInt(*this) -= other; }
    ModInt operator*(const ModInt &other) const { return ModInt(*this) *= other; }
    ModInt operator/(const ModInt &other) const { return ModInt(*this) /= other; }
    friend ModInt operator++(ModInt &x, int)
    {
        ModInt ret = x;
        ++x;
        return ret;
    }
    friend ModInt operator--(ModInt &x, int)
    {
        ModInt ret = x;
        --x;
        return ret;
    }
    friend bool operator<(const ModInt &a, const ModInt &b) { return a.val < b.val; }
    friend bool operator>(const ModInt &a, const ModInt &b) { return a.val > b.val; }
    bool operator==(const ModInt &other) const { return val == other.val; }
    bool operator!=(const ModInt &other) const { return val != other.val; }
    friend ostream &operator<<(ostream &os, const ModInt &x) { return os << x.val; }
    friend istream &operator>>(istream &is, ModInt &x)
    {
        int64_t p;
        is >> p;
        x = ModInt(p);
        return is;
    }
    ModInt inv() const
    {
        ModInt ret;
        ret.val = invmod(val, MOD);
        return ret;
    }
    friend ModInt inv(const ModInt &x) { return x.inv(); }
    ModInt nega() const
    {
        ModInt ret;
        ret.val = (val ? MOD - val : 0);
        return ret;
    }
    friend ModInt nega(const ModInt &x) { return x.nega(); }
    ModInt operator-() const { return nega(); }
    ModInt operator+() const { return ModInt(*this); }
};

template <typename T>
T pow(T a, int64_t b)
{
    assert(b >= 0);
    T ret = 1;
    while (b)
    {
        if (b & 1)
            ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

template <int M>
string to_string(ModInt<M> x)
{
    return to_string(int(x));
}

using mint = ModInt<998244353>;

const int mxN = (int)(5e5+1);
vector<mint> fact, ifact;

void precalc()
{
    fact.resize(mxN);
    ifact.resize(mxN);
    fact[0] = mint(1);
    for (int i=1; i<mxN; i++) fact[i] = fact[i-1]*mint(i);
    ifact[mxN-1] = fact[mxN-1].inv();
    for (int i=mxN-1; i>=1; i--) ifact[i-1] = ifact[i]*mint(i);
}

mint dpdp(const v32 &a, int val)
{
    vector<mint> dp(val+1, mint(0));
    dp[0] = mint(1);
    for (auto x: a)
    {
        for (int i=val; i>=x; i--) dp[i] += dp[i-x];
    }
    return dp[val];
}

void sol()
{   
    v32 c(26);
    for (auto &x: c) cin >> x;
    ll s = accumulate(all(c), 0ll);

    bool ok = 1;
    for (int i=0; i<26; i++)
    {
        if (c[i] > (s+1)/2)
        {
            ok = 0;
            break;
        }
    }
    if (!ok)
    {
        cout << 0 << el;
        return;
    }

    int tot = 0;
    v32 a;
    for (int i=0; i<26; i++)
    {
        if (!c[i]) continue;
        if (c[i] > s/2) tot += c[i];
        else a.pb(c[i]);
    }

    if ((s+1)/2-tot < 0)
    {
        cout << 0 << el;
        return;
    }
    ll new_s = accumulate(all(a), 0ll);
    if ((s+1)/2-tot > new_s)
    {
        cout << 0 << el;
        return;
    }

    mint cnt = dpdp(a, (s+1)/2-tot), factor = fact[(s+1)/2]*fact[s/2];
    for (int i=0; i<26; i++) factor *= ifact[c[i]];
    cout << mint(cnt*factor) << el;
}

nbzzz()
{
    io();
    precalc();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}