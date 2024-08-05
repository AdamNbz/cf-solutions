#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s2, s="";
    getline(cin, s1);
    getline(cin, s2);
    for (int i=0; i<s1.length(); i++)
    {
        if (s1[i] == s2[i]) s += '0';
        else s += '1';
    }
    cout << s;
}