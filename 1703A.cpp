#include <bits/stdc++.h>
#define el cout<<"\n"
using namespace std;
string s;
void runCase(){
    getline(cin, s);
    if (s == "YES" || s == "yES" || s == "yeS" || s == "yes" || s == "Yes" || s == "YEs" || s == "YeS" || s == "yEs") cout << "YES";
    else cout << "NO";
    el;
}


int main(){
    int t;
    cin >> t;
    getline(cin, s);
    while (t--){
        runCase();
    }
}