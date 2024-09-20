/*
Author : Nguyen Vo Ngoc Bao
School : University of Information Technology, VNU-HCM
*/
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define el '\n'
#define pb push_back
#define eb emplace_back
#define io() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define mask(i) (1LL << (i))
#define getbit(mask, i) (((mask) >> (i)) & 1)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<ll> v64;
typedef vector<vector<ll> > vv64;
typedef vector<p32> vp32;
typedef vector<vector<p32> > vvp32;
typedef vector<p64> vp64;
typedef vector<vector<p64> > vvp64;
typedef vector<bool> vb;
typedef vector<vector<bool> > vvb;
typedef vector<string> vs;
typedef vector<vs > vvs;

int pop_cnt(ll mask) { return __builtin_popcountll(mask); }
int ctz(ull mask) { return __builtin_ctzll(mask); }
int logOf(ull mask) { return 63 - __builtin_clzll(mask); }

const ll mod = (ll)(1e9+7);
const ll inf = (ll)(2e18);

bool query(string s)
{
    cout << "? " << s << endl;
    int n; cin >> n;
    return n;
}

void sol()
{
    int n; cin >> n;
    string pw = "0";
    if (!query(pw))
    {
        string ans = "";
        for (int i=1; i<=n; i++) ans += "1";
        cout << "! " << ans << endl;
        return;
    }
    int s = 0;
    for (int i=2; i<=n; i++)
    {
        if (!s)
        {
            string tmp = pw + "0";
            if (query(tmp)) pw = tmp;
            else
            {
                tmp = pw + "1";
                if (query(tmp)) pw = tmp;
                else
                {
                    s = 1;
                    tmp = "0" + pw;
                    if (query(tmp)) pw = tmp;
                    else pw = "1" + pw;
                }
            }
        }
        else
        {
            string tmp = "0" + pw;
            if (query(tmp)) pw = tmp;
            else pw = "1" + pw;
        }
    }
    cout << "! " << pw << endl;
}

int32_t main()
{
    io();
    int t; cin >> t;
    while (t--) sol();
    cerr << "\nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << "ms\n";
}