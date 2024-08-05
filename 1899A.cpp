#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

void Solve()
{
    int n; cin >> n;
    int a = n+1, b = n-1;
    (a % 3 == 0 || b % 3 == 0) ? cout << "First" : cout << "Second";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
        Solve();
}
