#include <bits/stdc++.h>
#define f first
#define s second
#define inf 1000000000

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

const ll mod = (ll)(1e9 + 7);

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}

int n;

void sol()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cout << i*(i+1) << " ";
    }
    //Solution:
    //for (int i=1; i<=n; i++) cout << i << " ";
    cout << endl;
}

int main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}

