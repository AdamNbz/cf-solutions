#include <bits/stdc++.h>
#pragma GCC optimize("O3")

using namespace std;
using ll = long long;

const static int mxN = (1e9);

void Solve()
{
    int l, r, a; cin >> l >> r >> a;
    if (l == r)
    {
        cout << l/a + l%a << endl;
        return;
    }
    int x = r;
    if (r % a != a-1)
    {
        x = (r/a)*a-1;
        if (x < l) x = r;
    }
    cout << x/a + x%a << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        Solve();
}
