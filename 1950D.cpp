#include <bits/stdc++.h>

using namespace std;

int mang[] = {10, 11, 101, 111, 1001};

void solve(){
    int n;
    cin>>n;
    int i = 4;
    while (n != 1 && i >= 0){
        while (n % mang[i] == 0) n/=mang[i];
        --i;
    }
    if (n == 1) {
        cout<<"YES\n";
    } else{
        cout<<"NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        solve();
    }
}
