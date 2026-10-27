#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,t; cin>>n>>t;
    map<int,vector<int>> m;
    vector<int> v(n);
    pair<int,int> p;
    
    for (int i = 0; i < n; i++) {
        cin>>v[i];
        m[v[i]].push_back(i+1);
    }
    while (t--)
    {
        cin>>p.first>>p.second;
        if (m.count(p.first) && m[p.first].size()>=p.second) {
            cout<<m[p.first][p.second-1]<<'\n';
        }
        else {
            cout<<-1<<'\n';
        }
    }
    return 0;
}  
