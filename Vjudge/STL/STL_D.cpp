#include<bits/stdc++.h>
using namespace std;
     
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while (t--) {
        
        int n; cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        set<int> us;
        int k = n-1;
        while (k>=0 && !us.count(v[k]))
        {
            us.insert(v[k]);
            k--;
        }
        cout <<k+1<<endl;
    }
    return 0;
}