#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

void Solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int time = 1;
    int cnt = 0;
    int ans[27]{};
    for (int i = 0; i<26; i++) ans[i] = i+1;
    int track[27]{};
    for (int i=0; i<n; i++) track[s[i] - 'A']++;
    for (int i=0; i<26; i++)
    {
        if (track[i] >= ans[i] && track[i] <= n)
        {
            cnt++;
            n -= track[i];
        }
    }
    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        Solve();
}
