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

long double n, m, a;

void sol()
{
    cin >> n >> m >> a;
    cout.precision(22);
    if (m < n) swap(m, n);
    if (a >= m) cout << ceil(n/a) << '\n';
    else cout << ceil(n/a) * ceil(m/a) << '\n';
}

int32_t main()
{
    init();
    sol();
}




