#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int t; cin>>t;
    while (t--)
    {
        int a,b,n,res;cin>>a>>b>>n;
        if (b*n >= 100) {
            res = (b*n)/100;
            cout<<a*n+res<<" "<<(b*n)-(100*res)<<'\n';
        }
        else {
            cout<<a*n<<" "<<b*n<<'\n';
        } 
    }
    return 0;
}