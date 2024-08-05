#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

void Solve()
{
    int n; cin >> n;
    vector <int> a(n); for (int i=0; i<n; i++) cin >> a[i];
    if (a[0] != a[1] && a[0] != a[2]) cout << 1 << endl;
    else if (a[0] != a[1] && a[1] != a[2]) cout << 2 << endl;
    else for (int i=2; i<n; i++)
    {
        if (a[i] != a[i-1])
        {
            cout << i+1 << endl;
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        Solve();
}
