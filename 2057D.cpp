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


struct SegmentTree {
    int n;

    struct Node {
        ll mxR=-inf;
        ll mnL=inf;
        ll bestConv=-inf;

        ll mxL = -inf;
        ll mnR = inf;
        Node()
        {
            bestConv = -inf;
            mxR = mxL = -inf;
            mnR = mnL = inf;
        }
    };
    vector<Node> tree;

    SegmentTree(int n_=0) : n(n_) {
        tree.resize(4*n+5);
        for (int i=1; i<=n*4; i++) tree[i] = Node();
    }

    Node merge(const Node &a, const Node &b) const {
		Node ans = Node();
		ans.bestConv = max(a.bestConv, b.bestConv);
		ans.bestConv = max(ans.bestConv, b.mxR - a.mnL);
		ans.bestConv = max(ans.bestConv, a.mxL - b.mnR);
		ans.mxR = max(a.mxR, b.mxR);
        ans.mxL = max(a.mxL, b.mxL);
        ans.mnR = min(a.mnR, b.mnR);
        ans.mnL = min(a.mnL, b.mnL);
		return ans;
	}

    void update(int l, int r, int pos, ll val, int idx) {
        if (l == r) {
            tree[idx].mxR = val-l;
            tree[idx].mxL = val+l;
            tree[idx].mnR = val+l;
            tree[idx].mnL = val-l;
            tree[idx].bestConv = 0;
            return;
        }
        int m = (l + r) >> 1;
        if (pos <= m) update(l, m, pos, val, idx<<1);
        else update(m+1, r, pos, val, idx<<1|1);

        tree[idx] = merge(tree[idx<<1], tree[idx<<1|1]);
    }

    ll getMaxConvenience() const {
        return tree[1].bestConv;
    }
};

void sol()
{
    int n, q; cin >> n >> q;
    SegmentTree st(n);
    for (int i=1; i<=n; i++) 
    {
        int x; cin >> x;
        st.update(1, n, i, x, 1);
    }
    cout << st.getMaxConvenience() << el;
    while (q--)
    {
        int p, x; cin >> p >> x;
        st.update(1, n, p, x, 1);
        cout << st.getMaxConvenience() << el;
    }
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}