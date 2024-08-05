#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}

void Solve()
{
    int a, b, c; cin >> a >> b >> c;
    if (a < b && b < c) cout << "STAIR";
    else if (a < b && c < b) cout << "PEAK";
    else cout << "NONE";
    cout << endl;
}

int main()
{
    int t; cin >> t;
    while (t--)
        Solve();
}
