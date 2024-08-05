#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int x = max({a, b, c});
    int sum = a + b + c + n;
    (sum%3==0 && sum/3>=x) ? cout << "YES" : cout << "NO";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
    {
        Solve();
    }
}