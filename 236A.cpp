#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin, s);
	sort(s.begin(), s.end());
	int ans=0;
	for (int i=1; i<s.length(); i++){
		if (s[i] != s[i-1]) ans++;
	}
	if (ans&1) cout << "CHAT WITH HER!";
	else cout << "IGNORE HIM!";
}
