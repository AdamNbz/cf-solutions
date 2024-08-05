#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2, s;
    cin >> s1 >> s2 >> s;
    string a = s1 + s2;
    sort (a.begin(), a.end());
    sort (s.begin(), s.end());
    (s == a) ? cout << "YES" : cout << "NO";
}
