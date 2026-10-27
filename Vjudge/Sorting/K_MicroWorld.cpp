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
    sort(v.rbegin(),v.rend());
    
    int c = v[0],co = 0;

    for (int i = 1; i < n; i++) {
        if (c > v[i] && c <= v[i]+k) {
            co++;
        }
        else {
            c = v[i-1];
            if (c > v[i] && c <= v[i] + k) {
                co++;
            }
        }
    }
    cout<<n-co;
    return 0;
}