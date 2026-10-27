#include<bits/stdc++.h>
using namespace std;
     
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    while (t--)
    {
        int n,j,k; cin>>n>>j>>k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
        }
        int num = v[j-1];
        int tam = v.size();
        
        sort(v.begin(),v.end());

        if (k == 1 && num < v[n-1] )    {
            cout<<"NO"<<'\n';
        }
        else    {
            cout<<"YES"<<'\n';
        }
    }
    return 0;
}