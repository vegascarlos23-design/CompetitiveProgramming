#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int t; cin>>t;
    while (t--) {
        long long n; cin>>n;
        if (n == 0) {
            cout<<0<<'\n';
            continue;
        }
        if (n>0) {
            cout<<1<<'\n';
            continue;
        }
        else {
            cout<<-1<<'\n';
        }
    }
    return 0;
}