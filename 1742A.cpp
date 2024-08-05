#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ld long double
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define all(x) x.begin(),x.end()
#define el cout<<"\n"
#define MAXN 1000006
#define MOD 1000000007

using namespace std;
int t, a, b, c;

void Solve(){
	cin >> a >> b >> c;
	if (a + b == c || b + c == a || a + c == b) {
		cout << "YES"; el;
	}
	else {
		cout << "NO"; el;
	}
}


int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(" ", "r", stdin);
    //freopen(" ", "w", stdout);
    cin >> t;
    while (t--){
    	Solve();
	}
}
