#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef long long ll;

const int N = 20+1, inf = 1e9+7;

int n;
string s;
int a[N];

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}


void sol()
{
    cin >> n >> s;
    if (n == 2)
    {
        cout << stoi(s) << '\n';
        return;
    }
    int ans = INT_MAX;
    for (int st=0; st<n-1; st++)
    {
        int cnt = 0;
        for (int i=0; i<n; i++)
        {
            if (i == st)
            {
                a[cnt++] = (s[i]-'0')*10 + (s[i+1]-'0');
                i++;
            }
            else a[cnt++] = s[i]-'0';
        }
        int val = 0;
        for (int i=0; i<cnt; i++)
        {
            if (a[i] == 0)
            {
                val = -1;
                break;
            }
            if (a[i] == 1) continue;
            val += a[i];
        }
        if (!val) val = 1;
        if (val == -1) val = 0;
        ans = min(ans, val);
    }
    cout << ans << '\n';
}

int main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}

