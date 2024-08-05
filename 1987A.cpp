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


void sol()
{
    int n, k; cin >> n >> k;
    cout << (n-1)*k+1 << '\n';
}

int32_t main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}




