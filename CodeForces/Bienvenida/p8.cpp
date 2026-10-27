#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int t; cin>>t;
    while (t--) {
        int k,p,s; cin>>k>>p>>s;
        int nc = (100+p)*k;
        int re = (s*100)/nc;
        cout<<re<<'\n';
    }
    return 0;
}