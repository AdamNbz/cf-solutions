#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		char a[n];
		int first = n-1;
		for (int i = 0 ; i < n ; ++i) cin>>a[i];
		for (int i = 0 ; i < n ; ++i){
			if (a[i] == 'A'){
				first = i;
				break;
			}
		}
		int len = 0;
		int ans = 0;
		for (int i = first ; i < n ;++i){
			if (a[i] == 'A'){
				++len;
			} else{
				ans+=len;
				len = 1;
			}
		}
		cout<<ans<<"\n";
	}
}