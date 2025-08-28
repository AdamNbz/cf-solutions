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

struct dsu
{
    int n;
    vector<int> par, s, r;
    dsu(int _n): n(_n), par(n), s(n, 1), r(n, 0) { iota(all(par), 0); }
    int get(int u) { return u == par[u] ? u : par[u] = get(par[u]); }
    int disjointSet() { return n; }
    int sizes(int u) { return s[get(u)]; }
    bool same(int u, int v) { return get(u) == get(v); }
    bool unite(int u, int v) 
    {
        u = get(u), v = get(v);
        if (u == v) return 0;
        if (r[u] < r[v]) swap(u, v);
        par[v] = u;
        r[u] += r[u] == r[v];
        s[u] += s[v];
        --n;
        return 1;
    }
};

void sol()
{
    int n, m; ll V;
    cin >> n >> m >> V;
    v64 a(n+1); for (int i=1; i<=n; i++) cin >> a[i];
    vvp32 g(n+1);
    vp32 e(m);
    for (int i=0; i<m; i++) 
    {
        int u, v; cin >> u >> v;
        e[i] = {u, v};
        g[u].pb({v, i});
        g[v].pb({u, i});
    }

    v32 d(n+1, 0), lo(n+1, 0);
    int cnt = 0;
    vp32 st;
    vvp32 cmp;
    auto dfs = [&](auto&& self, int u, int p) -> void
    {
        d[u] = lo[u] = ++cnt;
        for (auto [v, i]: g[u])
        {
            if (!d[v]) 
            {
                st.pb({u, v});
                self(self, v, i);
                ckmin(lo[u], lo[v]);
                if (lo[v] >= d[u]) 
                {
                    vp32 cmp2;
                    while (!st.empty())
                    {
                        auto w = st.back(); st.pop_back();
                        cmp2.pb(w);
                        if (w.fi == u && w.se == v) break;
                    }
                    cmp.pb(move(cmp2));
                }
            }
            else if (i != p && d[v] < d[u])
            {
                st.pb({u, v});
                ckmin(lo[u], d[v]);
            }
        }
    };

    dfs(dfs, 1, -1);
    dsu D(n);
    vector<char> equal(n+1, 0), zeros(n+1, 0);
    for (auto x: cmp)
    {
        set<int> ver;
        for (auto s: x) ver.insert(s.fi), ver.insert(s.se);
        if (sz(x) == 1) continue;

        v32 vs(all(ver));
        map<int, int> id;
        for (int i=0; i<sz(vs); i++) id[vs[i]] = i;

        vv32 g2(sz(vs));
        for (auto s: x) g2[id[s.fi]].pb(id[s.se]), g2[id[s.se]].pb(id[s.fi]);

        v32 col(sz(vs), -1);
        bool yesbip = 1;
        for (int i=0; i<sz(vs) && yesbip; i++) if (col[i] == -1)
        {
            queue<int> q; col[i] = 0;
            q.push(i);
            while (!q.empty() && yesbip)
            {
                int u = q.front(); q.pop();
                for (auto v: g2[u])
                {
                    if (col[v] == -1) 
                    {
                        col[v] = col[u] ^ 1;
                        q.push(v);
                    }
                    else if (col[v] == col[u]) 
                    {
                        yesbip = 0;
                        break;
                    }
                }
            }
        }

        if (!yesbip) for (auto x: vs) zeros[x] = 1;
        else 
        {
            for (int i=1; i<sz(vs); i++) D.unite(vs[0]-1, vs[i]-1);
            for (auto x: vs) equal[x] = 1;
        }
    }

    for (int i=1; i<=n; i++) if (zeros[i] && a[i] != -1 && a[i] != 0)
    {
        cout << 0 << el;
        return;
    }

    map<int, v32> mem;
    for (int i=1; i<=n; i++) if (equal[i]) mem[D.get(i-1)].pb(i);

    ll cnt2 = 0;
    for (auto x: mem)
    {
        ll fix = -1;
        for (auto u: x.se) if (zeros[u])
        {
            if (fix == -1) fix = 0;
            else if (fix != 0) 
            {
                cout << 0 << el;
                return;
            }
        }

        for (auto u: x.se) if (a[u] != -1)
        {
            if (fix == -1) fix = a[u];
            else if (fix != a[u]) 
            {
                cout << 0 << el;
                return;
            }
        }

        if (fix == -1) cnt2++;
    }

    for (auto i=1; i<=n; i++) 
    {
        if (equal[i]) continue;

        if (zeros[i])
        {
            if (a[i] != -1 && a[i] != 0) 
            {
                cout << 0 << el;
                return;
            }
        }
        else if (a[i] == -1) cnt2++;
    }

    mint ans = pow(mint(V), cnt2);
    cout << ans << el;
}

nbzzz()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}