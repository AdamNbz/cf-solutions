#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n+1];
    for (int i= 1; i <= n; ++i){
        cin >> a[i];
    }
    int check[100001];
    int sum =0;
    for (int i=1 ; i <= 100000 ; i++){
        check[i]=0;
    }
    for (int i=1;i <=n ;i++){
        check[a[i]]++;
    }
    //th1
    for (int i=1 ; i <= 100000 ; i++){
        sum += (check[i])?1:0;
        // if (check[i])
            // cout << i << "\n";
    }
    // cout << sum << "\n";
    
    if (sum == 1){
        cout << "YES\n";
    }
    else {
        if (sum > 2) 
        {
            cout << "NO\n";
        }
        else{
            int f_mem = a[1];
            int s_mem = 0;
            for (int i = 2; i<=n ; i++){
                if (a[i] != f_mem ){
                    s_mem = a[i];
                    break;
                }
            }
            if (n % 2){
                if (abs(check[f_mem] - check[s_mem]) == 1){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
            else{
                if (abs(check[f_mem] - check[s_mem]) == 0){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }
    }

}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}