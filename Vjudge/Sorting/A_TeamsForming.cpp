#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int sum=0;
    for (int j = n; j > 0; j-=2)
    {
        sum += v[j-1] - v[j-2];
    }
    cout<<sum;
    return 0;
}