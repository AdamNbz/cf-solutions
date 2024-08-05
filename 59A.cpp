#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	getline(cin, s);
	int countLower=0, countUpper=0;
	for (int i=0; i<s.length(); i++){
		if (s[i] >= 'a' && s[i] <= 'z') {
			++countLower;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			++countUpper;
		}
	}
	if (countLower < countUpper) {
		for (int i=0; i<s.length(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
		}
	}
	else {
		for (int i=0; i<s.length(); i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
		}
	}
	cout << s;
}
