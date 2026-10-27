#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,x,y; cin>>a>>x>>y;
    int minp = min(x,y), mxp = max(x,y);
    for (int i = minp; i < mxp; i++)
    {
        if (i == a){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}