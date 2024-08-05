#include<bits/stdc++.h>

using namespace std;

int main(){
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	long int sums1=0, sums2=0;
	for (int i=0; i<s1.size(); i++)
	{
		s1[i] = (char)tolower(s1[i]);
		s2[i] = (char)tolower(s2[i]);
	}
	for (int i=0; i<s1.size(); i++)
	{
		if (s1[i] < s2[i]) 
		{
			cout << -1;
			return 0;
		}
		if (s2[i] < s1[i])
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}
