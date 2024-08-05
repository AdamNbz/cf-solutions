#include <bits/stdc++.h>
#define pb push_back
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define all(x) x.begin(),x.end()
#define el cout<<"\n"
#define MAXN 1000006
#define MOD 1000000007
#define FI " .INP"
#define FO " .OUT"

typedef long long ll;
typedef long double ld;

using namespace std;

//template giai de hsgtp
void Nhap(){
	
}

void Solve(){
	
}

void Xuat(){
	
}

//Template cho codeforces
void runCase(){
	int n;
	cin >> n;
	vector <ll> a;
	a.resize(n);
	f0(i, n){
		cin >> a[i];
	}
	ll ans = 1;
	f0(i, n){
		ans *= a[i];
	}
	ans = (ans+(n-1))*2022;
	cout << ans; el;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(" ", "r", stdin);
    //freopen(" ", "w", stdout);
    int t;
    cin >> t;
    while (t--){
    	runCase();
	}
}