#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto& x : v) cin>>x;
    ll increment = 0, ans = 0;

    for (int i = 0; i < n-1; i++) {
        if (v[i] > v[i+1]) {
            increment = v[i] - v[i+1];
            v[i+1]+= increment;
            ans += increment;
        }
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}