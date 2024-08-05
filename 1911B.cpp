#include <bits/stdc++.h>
#pragma GCC optimize("02")

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    string ans = "";
    if (n >= 2)
    {
         ans += s[0]; ans += s[1];
    }
    else cout << s;
    int k = 3;
    for (int i=3; i<n;)
    {

        ans += s[i];
        i += k;
        k++;
    }
    cout << ans;
}
