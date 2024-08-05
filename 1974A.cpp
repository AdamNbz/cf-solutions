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

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int x, y;

void sol()
{
    cin >> x >> y;
    int ans = (y+1)/2;
    x -= (ans*5*3 - y*2*2);
    x = max(x, 0);
    ans += (x+5*3-1)/(5*3);
    cout << ans << '\n';
}

int32_t main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}
