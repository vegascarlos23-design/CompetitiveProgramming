#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> v(n);
    for (auto& x: v) cin>>x;
    int z = 3,o = 1,t = 1,tw = 2,f = 1;
    if (n < 8){
        cout<<0<<'\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == 0) z--;
        if (v[i] == 1) o--;
        if (v[i] == 3) t--;
        if (v[i] == 2) tw--;
        if (v[i] == 5) f--;
        if (z <= 0 && o <= 0 && t <= 0 && tw <= 0 && f <= 0){
            cout<<i+1<<'\n';
            return;
        }
    }
    cout<<0<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}