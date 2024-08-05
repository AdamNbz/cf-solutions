#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int a, b; cin >> a >> b;
        int cnt = 1, tmp = abs(a-b);
        if (tmp % 10 != 0) cnt += abs(tmp/10);
        else cnt = abs(cnt - 1 + (tmp/10));
        cout << cnt << endl;
    }
}