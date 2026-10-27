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
    sort(v.rbegin(),v.rend());
    
    vector<long long> v1;

    for (int i = 0; i < n-1; i++)
    {
       if (v[i] == v[i+1]) {
            v1.push_back(v[i]);
            i++;
            if (v1.size() == 2) {
                cout<<v1[0]*v1[1];
                return 0;
            }
       }
    }
    cout<<0;
    return 0;
}