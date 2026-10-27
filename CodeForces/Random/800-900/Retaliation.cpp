#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;  cin>>n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin>>v[i]; 

        int y = (2*v[0] - v[1])/(n+1);
        int x = v[1]-v[0] + y;

        if (x<0 || y<0) {
            cout <<"NO"<<'\n';
            return;
        }

        for(int i = 0; i < n; i++) {
            v[i] -= x*(i + 1);
            v[i] -= y*(n - i);
        }

        for(int i = 0; i < n; i++) {
            if(v[i] == 0) continue; 
            cout <<"NO"<<'\n';
            return;
        }
        cout<<"YES"<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)  {
        solve();
    }
    return 0;
}