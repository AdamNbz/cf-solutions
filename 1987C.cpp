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
    vi h(n);
    for (int i=0; i<n; i++) cin >> h[i];
    ll ans = h[n-1];
    for (int i=n-2; i>=0; i--) ans = max(ans+1, (ll) h[i]);
    cout << ans << el;
}

int32_t main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}




