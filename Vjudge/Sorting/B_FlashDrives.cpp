#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m; cin>>n>>m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    
    sort(v.begin(),v.end());
    int sum=0;
    for (int j = n; j > 0; j--)
    {
        sum += v[j-1];
        if (sum >= m)
        {
            cout<<n-(j-1);
            return 0;
        }
    }
    return 0;
}