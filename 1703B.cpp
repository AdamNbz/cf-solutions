#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        set <int> st;
        for (char x:s) st.insert(x);
        cout << n + st.size() << "\n";
    }
}
