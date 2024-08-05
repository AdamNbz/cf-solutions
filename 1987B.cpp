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
    vi a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    ll pref = 0, s = 0, mxN = 0;
    for (int i=0; i<n; i++)
    {
        pref = max(pref, (ll) a[i]);
        ll d = pref - a[i];
        s += d;
        mxN = max(mxN, d);
    }
    cout << s + mxN << el;
}

int32_t main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}