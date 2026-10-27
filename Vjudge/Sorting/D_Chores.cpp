#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    int i1 = n-a;
    cout<<v[i1]-(v[i1-1]);
    return 0;
}