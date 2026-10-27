#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c; cin>>a>>b>>c;
    if (c-(b-a) >= b && (a+b+c)%3 == 0) {
        cout<<"YES"<<'\n';
        return;
    }
    cout<<"NO"<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}