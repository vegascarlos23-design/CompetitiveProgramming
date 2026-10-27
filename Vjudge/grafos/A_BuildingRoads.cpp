#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n,e; cin>>n>>e;
    
    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1);
    vector<int> ans;
    while (e--)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for (auto c : adj[u]) {
        if (vis[c]) continue;
        dfs(c);
        }
    };
    
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i);
        ans.push_back(i);
    }
    
    cout<<ans.size()-1<<'\n';
    for (int i = 0; i < ans.size()-1; i++) {
        cout<<ans[i]<<" "<<ans[i+1]<<'\n';
    }
    return 0;
}