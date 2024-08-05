#include <bits/stdc++.h>
#define pb push_back
 
using namespace std;
 
int main(){
	long long n;
	int cnt=0;
	cin >> n;
	long long tmp = n;
	vector <int> b;
	while (tmp > 0){
		b.pb(tmp%10);
		tmp /= 10;
	}
	/*for (int i=0; i<b.size(); i++){
		cout << b[i] << " ";
	}*/
	for (int i=0; i<b.size(); i++){
		if (b[i] == 4 || b[i] == 7) cnt++;
	}
	//cout << cnt << " ";
	if (cnt == 7 || cnt == 4) cout << "YES";
	else cout << "NO";
}
