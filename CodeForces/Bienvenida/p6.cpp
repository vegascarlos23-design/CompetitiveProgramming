#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int t; cin>>t;
    while (t--)
    {
        int a,b,l,n; cin>>a>>b>>l>>n;
        if (n == 1) {
            cout<<2*l +a<<'\n';
        }
        else {
            cout<<(n-1)*(2*a+2*b)+2*l+a<<'\n';
        }
    }
    return 0;
}