#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n,m,k; cin>>n>>m>>k;
    ll re = k/n;
    
    if (re*n != k) re += k%n;  

    if (re == m) {
        cout<<re<<'\n';
        return;
    }
    if (m == 2) {
        cout<<1<<'\n';
        return;
    }
    if (m%2 == 0) {
        
    }
    else {
        
    }
    
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}