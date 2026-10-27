#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c,d; cin>>a>>b>>c>>d; 
    int minG = min(a,c),minF = min(b,d);
    if (minG >= minF)   {
        cout<<"Gellyfish"<<'\n';
    }
    else {
        cout<<"Flower"<<'\n';
    }   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  {
        solve();
    }
    return 0;
}