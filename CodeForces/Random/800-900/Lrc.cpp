#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> v(n),vr;    
    for (int i = 0; i < n; i++) cin>>v[i];
    int mx = *max_element(v.begin(),v.end());
    int min = *min_element(v.begin(),v.end());
    if (min == mx) {
        cout<<"NO"<<'\n';
        return;
    }
    else {
        cout<<"YES"<<'\n';
        for (int i = 0; i < n; i++) {
            if (mx == v[i]) cout<<2<<" ";
            else cout<<1<<" ";
        }
    }
    cout<<'\n';  
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}