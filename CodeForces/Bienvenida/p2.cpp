#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    string n; cin>>n;
    if (n.size() >= 2) {
        cout<<n[n.size()-2];
        return 0;
    }
    cout<<0;
    return 0;
}