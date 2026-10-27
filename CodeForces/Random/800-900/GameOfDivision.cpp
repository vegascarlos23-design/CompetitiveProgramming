#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,x; cin>>n>>x;
        vector<int> v(n);
        map<int,int> mp;
        for (int i = 0; i < n; i++){
            cin>>v[i];
            v[i] %= x;
            mp[v[i]]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (mp[v[i]]==1) {
                cout<<"YES"<<'\n'<<i+1<<'\n';
                return;
            }
        }
        cout<<"NO"<<'\n';
    }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--)  {
        solve();
    }
    return 0;
} 
