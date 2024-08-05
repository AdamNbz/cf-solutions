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

int n;
string s, s1;

void sol()
{
    cin >> n >> s;
    s1 = s;
    sort(s1.begin(), s1.end());
    (s1 == s) ? cout << "YES\n" : cout << "NO\n";
}

int32_t main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}



