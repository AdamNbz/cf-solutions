#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int ans=0;
	while (n--){
		int a, b, c;
		cin >> a >> b >> c;
		int t = a + b + c;
		if (t>1) ans++;
	}
	cout << ans;
}
