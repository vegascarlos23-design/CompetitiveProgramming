#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n; cin>>n;
    if (n%2==0){
        cout<<n/2<<" "<<n/2<<'\n';
        return;
    }
    ll mx = 1;
    for (ll i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            ll re = n / i;
            mx = max(mx, i);
            mx = max(mx, re);
        }
    }
    cout<<mx<<" "<<n - mx<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}