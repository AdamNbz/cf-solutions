#include <bits/stdc++.h>

using namespace std;

void Solve()
{
    string n1, n2; cin >> n1 >> n2;
    if (n1.size() < n2.size())
    {
        int d = n2.size() - n1.size();
        string tmp = "";
        for (int i=0; i<d; i++)
        {
            tmp.push_back('0');
        }
        n1 = tmp + n1;
    }
    int ans = 0;
    for (int i=0; i<n1.size(); i++)
    {
        if (n1[i] != n2[i])
        {
            ans += abs(n1[i] - n2[i]);
            ans += 9 * (n1.size() - i - 1);
            break;
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
