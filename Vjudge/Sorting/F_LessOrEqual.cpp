#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k; cin>>n>>k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    
    if (k == 0) {
        if (v[0] > 1) {
            cout<<1;
            return 0;
        }
        cout<<-1;
        return 0;
    }

    if (v[k-1] != v[k] || n == k) {
        cout<<v[k-1];
        return 0;
    }

    cout<<-1;
    return 0;
}