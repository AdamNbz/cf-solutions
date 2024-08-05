#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef long long ll;

const int N = 1e5+5;

int n, m;
string s, t;
int ind[N], cnt[N];
pii p[N];

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}


void sol()
{
    cin >> n >> m >> s;
    memset(cnt, 0, sizeof cnt);
    for (int i=0; i<m; i++)
    {
        cin >> ind[i];
        ind[i]--;
        p[i] = {cnt[ind[i]]++, ind[i]};
    }
    cin >> t;
    sort(p, p+m);
    sort(t.begin(), t.end());
    for (int i=m-1; i>=0; i--) s[p[i].s] = t[i];
    cout << s << '\n';
}

int main()
{
    init();
    int t; cin >> t;
    while (t--) sol();
}

