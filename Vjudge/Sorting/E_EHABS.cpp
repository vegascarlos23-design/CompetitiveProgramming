#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin>>n;
    vector<int> v(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin>>v[i];
    }
    
    sort(v.begin(),v.end());
    int s1=0,s2=0;

    for (int i = 0; i < n; i++) {
        s1 += v[i];
    }
    
    for (int i = n; i < n*2; i++) {
        s2 += v[i];
    }
    
    if (s1 != s2)
    {
        for (int i = 0; i < n*2; i++) {
            cout<<v[i]<<" ";
        }
        
    }
    else {
        cout<<-1;
    }
    return 0;
}