#include <bits/stdc++.h>

using namespace std;


int main(){
	int n;
	cin >> n;
	if (n <= 10) {
		int ans = 1;
		if (n <= 5) cout << ans;
		else {
			++ans;
			cout << ans;
		}
	}
	else {
		int ans = n/5;
		n %= 5;
		if (n > 0) ++ans;
		cout << ans;
	}
}
