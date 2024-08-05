#include <bits/stdc++.h>
#pragma GCC optimize ("03")

using namespace std;

int main()
{
    int n; cin >> n;
    int p, f[n];
    for (int i=1; i<=n; i++)
    {
        cin >> p;
        f[p] = i;
    }
    for (auto i = 1; i <= n; i++)
        cout << f[i] << " ";
}
