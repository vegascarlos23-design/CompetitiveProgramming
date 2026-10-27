#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int t; cin>>t;
    while (t--)
    {
        long long a,b,c=1; cin>>a>>b;
        if (abs((a-b)/2) == 0) {
            cout<<1<<'\n';
            continue;
        }
        if ((a%2 != 0 && b%2 == 0 && a>b) || (a%2 == 0 && b%2 != 0 && a<b)) {
            cout<<abs((a-b)/2) + 1<<'\n';
        }
        else {
            cout<<abs((a-b)/2)<<'\n';
        }   
    }
    return 0;
}