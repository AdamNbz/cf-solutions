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

void Solve()
{
    int n; cin >> n;
    vector <int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    int mi = *min_element(a.begin(), a.end());
    if (count(a.begin(), a.end(), mi) == 1)
    {
        cout << "YES\n";
        return;
    }
    for (int i=0; i<n; i++)
    {
        if (a[i] % mi != 0)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    init();
    int t; cin >> t;
    while (t--)
        Solve();
}

