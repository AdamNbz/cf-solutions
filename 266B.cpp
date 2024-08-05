#include <bits/stdc++.h>
#pragma GCC optimize ("03")

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, t; cin >> n >> t;
    string s; cin >> s;
    while (t--)
    {
        for (int i=1; i<n; i++)
        {
            if (s[i] == 'G' && s[i-1] == 'B')
            {
                s[i] = 'B';
                s[i-1] = 'G';
                i++;
            }
        }
    }
    cout << s;
}
