#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int ans = 0;
	while (n--){
		string s;
		cin >> s;
		int t = s.length();
		for (int i=0; i<t; i++){
			if (s[i] == '+') {
				ans++;
				break;
			}
			else if (s[i] == '-'){
				ans--;
				break;
			}
		}
	}
	cout << ans;
}
