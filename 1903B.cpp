#include <bits/stdc++.h>
#pragma GCC Optimize("02")

using namespace std;

void Solve()
{
    int n; cin >> n;
    string s; cin >> s;
    if (s.find("...") != string::npos) cout << 2 << endl;
    else cout << count(s.begin(), s.end(), '.') << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        Solve();
}
