#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        long long ans = 0;
        double n; cin >> n;
        ans = ceil((n/2)-1);
        cout << ans << "\n";
    }
}