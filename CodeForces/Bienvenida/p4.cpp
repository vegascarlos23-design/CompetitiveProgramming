#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    long long t; cin>>t;
    while (t--)
    {
        int n; cin>>n;
        if (n%2 != 0) {
            cout<<n+1<<'\n';
        }
        else {
            cout<<n+2<<'\n';
        }
    }
    return 0;
}