#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    set<int> m;
    vector<int> v(n);
    vector<int> r;
    for (int i = 0; i < n; i++)
    {
        cin>> v[i];
        int id = i+1;
        
        if (!m.count(id)) {
            m.insert(v[i]);
        }
    }   
    for (int i = 1; i <= n; i++) {
        if (!m.count(i)) {
            r.push_back(i);
        }
    }
    cout<<r.size()<<"\n";
    for (int ids : r) {
        cout<<ids<<" ";
    }
    
    
    return 0;
}