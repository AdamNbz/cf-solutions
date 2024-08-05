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
    int a, b, l; cin >> a >> b >> l;
    set<int> c;
    for (int i=1; i<=l; i*=a)
    {
        for (int j=1; j*i<=l; j*=b)
        {
            if (l % (i*j) == 0) c.insert(i*j);
        }
    }
    cout << c.size() << endl;
}

int main()
{
    init();
    int t; cin >> t;
    while (t--)
        Solve();
}
