#include <bits/stdc++.h>
#define fi first
#define se second
#define inf 1000000000
#define el '\n'
#define pb push_back

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

const ll mod = (ll)(1e9+7);

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

string transfer(string s, int a, int b)
{
    string ans = "";
    for (int i=0; i<a; i++) ans += s;
    if (ans.length() <= b) ans = "";
    int idx_len = ans.length()-1-b;
    return ans.substr(0, max(0, idx_len));
}

void sol()
{
    int n; cin >> n;
    vector<pair<int,int>> ans;
    string s = to_string(n);
    int l = int(s.size());
    for (int len=1; len<=6; len++)
    {
        string v;
        for (int i=0; i<len; i++) v += s[i%l];
        ll val = stoll(v);
        for (ll a = 1; a<=10000; a++)
        {
            ll b = n*a-val;
            if (1 <= b && b <=10000 && l*a-b == len) ans.pb({a, b});
        }
    }
    cout << ans.size() << el;
    for (auto &[a, b]: ans) cout << a << " " << b << el;
}

int32_t main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}