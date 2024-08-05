#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
void Solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int sumofB = 0;
    for (int i=0; i<n; i++)
    {
        sumofB += s[i] == 'B';
    }
    if (sumofB == k) cout << 0;
    else
    {
        cout << 1 << endl;
        if (k > sumofB)
        {
            int sumofA=0, ans;
            for (int i=0; i<n; i++)
            {
                sumofA += s[i] == 'A';
                if (sumofA + sumofB >= k)
                {
                    ans = i + 1;
                    break;
                }
            }
            cout << ans << " B";
        }
        else
        {
            int ans = 0, cnt=0;
            for (int i=0; i<n; i++)
            {
                cnt += s[i] == 'B';
                if (sumofB - cnt <= k)
                {
                    ans = i + 1;
                    break;
                }
            }
            cout << ans << " A";
        }
    }
    cout << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while (t--)
        Solve();
}