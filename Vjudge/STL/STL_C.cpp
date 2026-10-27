#include<bits/stdc++.h>
using namespace std;
     
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    set<int> v;
    for (int i = 0; i < n; i++) {
        int a; cin>>a;
        v.insert(a);
    }
    cout<<v.size();  
    return 0;
}