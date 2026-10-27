#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)  {
        int n,x; cin>>n>>x;
        bool a = 0,b = 1;
        vector<int> v(n+x,0);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 1 && !a) {
                a = 1;
                i += x;
            }
            if (a && v[i] == 1) b = 0;
        }
        b ? cout<<"YES"<<'\n' : cout<<"NO"<<'\n';

    }
    return 0;
}