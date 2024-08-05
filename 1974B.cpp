#include <bits/stdc++.h>
#define f first
#define s second
#define inf 1000000000

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

const ll mod = (ll)(1e9+7);

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

void sol()
{
    int n;
    string s, t = "";
    vector<int> cnt(26, 0);
    cin >> n >> s;
    cnt.resize(26, 0);
    for (auto c: s) cnt[c-'a'] = 1;
    for (int i=0; i<26; i++) if (cnt[i] > 0) t += char('a'+i); 
    string ans = "";
    for (auto c: s) ans += t[t.size()-1-t.find(c)];
    cout << ans << '\n';
}

int32_t main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}
