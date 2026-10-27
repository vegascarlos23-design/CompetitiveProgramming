#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n,k; cin>>n>>k;
    vector<ll> v(n);
    for (auto& x: v) cin>>x;
    sort(v.rbegin(),v.rend());
    ll cur = 1, c = 0;
    for (int i = 0; i < n; i++) {
        if (v[i]*cur >= k) {
            c++;
            cur = 1;
        }
        else cur++;
    }
    cout<<c<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}