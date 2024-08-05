#include <bits/stdc++.h>
#define pb push_back
#define f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define all(x) x.begin(),x.end()
#define el cout<<"\n"
#define MAXN 1000006
#define MOD 1000000007
 
typedef long long ll;
typedef long double ld;
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(" ", "r", stdin);
    //freopen(" ", "w", stdout);
    int n, cntD=0, cntA=0;
    string s;
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    f0(i, n){
    	if (s[i] == 'D') ++cntD;
    	else ++cntA;
	}
	if (cntA > cntD) cout << "Anton";
	else if (cntA < cntD) cout << "Danik";
	else cout << "Friendship";
}