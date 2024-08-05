#include <bits/stdc++.h>
#define f first
#define s second
#define inf 1000000000
#define el '\n'

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;


const ll mod = (ll)(1e9+7);

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

void sol()
{
    int n; cin >> n;
    vll a(n);
    for (auto &x: a) cin >> x;
    map<tuple<ll, ll, ll>, ll> cnt;
    ll ans = 0;
    for (int i=0; i<n-2; i++)
    {
        tuple<ll, ll, ll> b = make_tuple(a[i], a[i+1], a[i+2]);
        vector<tuple<ll, ll, ll>> c(3);
        c[0] = {0, a[i+1], a[i+2]}, c[1] = {a[i], 0, a[i+2]}, c[2] = {a[i], a[i+1], 0};
        for (auto x: c)
        {
            ans += cnt[x] - cnt[b];
            cnt[x]++;
        }
        cnt[b]++;
    }
    cout << ans << el;
}

int32_t main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}
