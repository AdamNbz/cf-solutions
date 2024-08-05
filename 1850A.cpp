#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void Solve()
{
    unsigned short int a, b, c;
    cin >> a >> b >> c;
    (a+b >= 10 || a+c >= 10 || b+c >= 10) ? cout << "YES" : cout << "NO";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        Solve();
    }
}