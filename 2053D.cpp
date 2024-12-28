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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
template<class T> 
using ordered_set = tree<
    T, null_type, less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int pop_cnt(ll mask) { return __builtin_popcountll(mask); }
int ctz(ull mask) { return __builtin_ctzll(mask); }
int logOf(ull mask) { return 63 - __builtin_clzll(mask); }
int parity(ull mask) { return __builtin_parityll(mask); }

static const ll MOD = 998244353;
const ll inf = numeric_limits<ll>::max();

inline ll modmul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

struct SegTree {
    int n;
    vector<ll> tree;
    SegTree(int n_){
        n=1; 
        while(n<n_) n<<=1;
        tree.assign(n<<1,1LL);
    }
    void build(const vector<ll> &arr){
        for(int i=0;i<(int)arr.size();i++){
            tree[n+i] = (arr[i] % MOD);
        }
        for(int i=n-1; i>=1; i--){
            tree[i] = modmul(tree[i<<1], tree[i<<1|1]);
        }
    }
    void update(int idx, ll val){
        idx += n;
        tree[idx] = (val % MOD);
        idx >>=1;
        while(idx>=1){
            tree[idx] = modmul(tree[idx<<1], tree[idx<<1|1]);
            idx>>=1;
        }
    }
    ll queryAll(){
        return tree[1];
    }
};
 
struct DynamicMinProd {
    int n;
    ordered_set< pair<ll,int> > dsA, dsB;
    SegTree segt;
    vector<ll> M;
    vector<ll> crrA, crrB;
 
    DynamicMinProd(int n_):n(n_), segt(n_){
        M.resize(n,1LL);
        crrA.assign(n,0LL);
        crrB.assign(n,0LL);
    }
    int getRankA(ll val, int idx){
        return (int) dsA.order_of_key({val, idx});
    }
    int getRankB(ll val, int idx){
        return (int) dsB.order_of_key({val, idx});
    }
    ll getValA(int r){
        auto it = dsA.find_by_order(r);
        return it->first;
    }
    ll getValB(int r){
        auto it = dsB.find_by_order(r);
        return it->first;
    }
    void build(const vector<ll> &a, const vector<ll> &b){
        for(int i=0;i<n;i++){
            dsA.insert({a[i], i});
            dsB.insert({b[i], i});
            crrA[i] = a[i];
            crrB[i] = b[i];
        }
        for(int k=0; k<n; k++){
            ll vA = getValA(k);
            ll vB = getValB(k);
            M[k] = min(vA, vB);
        }
        segt.build(M);
    }
    void recalcRange(int L, int R){
        if(R < 0 || L >= n) return;
        if(L<0) L=0; 
        if(R>=n) R=n-1;
        if(L>R) return;
 
        for(int k=L; k<=R; k++){
            ll vA = getValA(k);
            ll vB = getValB(k);
            ll newMin = min(vA,vB);
            if(newMin != M[k]){
                M[k] = newMin;
                segt.update(k, newMin);
            }
        }
    }
    void updA(int x){
        ll oldVal = crrA[x];
        ll newVal = oldVal + 1;
        crrA[x] = newVal;
        int rOld = getRankA(oldVal,x);
        dsA.erase({oldVal,x});
        dsA.insert({newVal,x});
        int rNew = getRankA(newVal,x);
 
        if(rOld>rNew) swap(rOld,rNew);
        recalcRange(rOld, rNew);
    }
    void updB(int x){
        ll oldVal = crrB[x];
        ll newVal = oldVal + 1;
        crrB[x] = newVal;
        int rOld = getRankB(oldVal,x);
        dsB.erase({oldVal,x});
        dsB.insert({newVal,x});
        int rNew = getRankB(newVal,x);
 
        if(rOld>rNew) swap(rOld,rNew);
        recalcRange(rOld,rNew);
    }
    ll getProduct(){
        return segt.queryAll();
    }
};

void sol()
{
    int n, q; cin >> n >> q;
    v64 a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    DynamicMinProd dmp(n);
    dmp.build(a, b);
    ll ans = dmp.getProduct();
    cout << ans%MOD << " ";
    while (q--)
    {
        int o; ll x; cin >> o >> x;
        x--;
        ll oldmn = min(a[x], b[x]);
        if (o == 1) dmp.updA((int)x);
        else dmp.updB((int)x);
        ll ret = dmp.getProduct();
        cout << ret%MOD << " ";
    }
    cout << el;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}