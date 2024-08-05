#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;
using ll = long long;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int a[100005];
bool nho[3];

void Solve()
{
    int n; cin >> n;
    memset(nho, 0, sizeof nho);
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        nho[a[i]%3] = 1;
    }
    ll sum = accumulate(a, a+n, sum);
    if (sum % 3 == 0) cout << "0\n";
    else if (nho[sum%3] || (sum % 3 == 2 && nho[1])) cout << "1\n";
    else cout << "2\n";
}

int main()
{
    init();
    int t; cin >> t;
    while (t--)
        Solve();
}
