#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

void fastIO()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    fastIO();
    int a, b, c; cin >> a >> b >> c;
    int ans = 0;
    ans = max(ans, a*b*c);
    ans = max(ans, (a+b)*c);
    ans = max(ans, a*(b+c));
    ans = max(ans, a+b+c);
    ans = max(ans, a+b*c);
    ans = max(ans, a*b+c);
    cout << ans;
}
