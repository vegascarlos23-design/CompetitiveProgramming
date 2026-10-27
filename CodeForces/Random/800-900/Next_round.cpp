#include<bits/stdc++.h>
using namespace std;
     
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,c = 0;
    cin>>n; cin>>k;
    vector<int> p(n);
    
    for (int i = 0; i < n; i++)
    {
        cin>>p[i]; 
    }
    for (int j = 0; j < n; j++)
    {
        if (p[j] >= p[k-1] && p[j] != 0)
        {
            c++;
        } 
    }
    cout<<c;
    return 0;
}