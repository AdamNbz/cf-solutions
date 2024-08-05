#include <bits/stdc++.h>
#define f first
#define s second
#define inf 1000000000

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const ll mod = (ll)(1e9+7);
const int N = 2e5+1;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, a[N], b[N];


void sol()
{
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<=n; i++) cin >> b[i];
    ll ans = INT_MAX;
    for (int i=0; i<n; i++)
    {
        ans = min<int>(ans, abs(a[i]-b[n]));
        ans = min<int>(ans, abs(b[i]-b[n]));
        if (min(a[i], b[i]) <= b[n] && b[n] <= max(a[i], b[i])) ans = 0;
    }
    for (int i=0; i<n; i++) ans += abs(a[i]-b[i]);
    cout << ans+1 << '\n';
}

int32_t main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}



