    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        vector <long long> N;
        for (int i=0; i<4; i++){
            long long tmp;
            cin >> tmp;
            N.push_back(tmp);
        }
        sort(N.begin(),N.end());
        cout << N[3]-N[0] << " " << N[3] - N[1] << " " << N[3] - N[2];
    }
