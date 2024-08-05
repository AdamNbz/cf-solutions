#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int l[27] = {0}, u[27] = {0};
    for (int i=0; i<n; i++) if (isupper(s[i])) u[s[i] - 'A']++;
    else l[s[i]-'a']++;
    int ans = 0;
    for (int i=0; i<26; i++)
    {
        if (l[i] == u[i]) ans += l[i];
        else if (l[i] > u[i])
        {
            ans += u[i];
            ans += min(k, (l[i] - u[i])/2);
            k -= min(k, (l[i] - u[i])/2);
        }
        else
        {
            ans += l[i];
            ans += min(k, (u[i] - l[i])/2);
            k -= min(k, (u[i] - l[i])/2);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        Solve();
}
