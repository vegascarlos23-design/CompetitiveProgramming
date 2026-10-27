#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int n,e; cin>>n>>e;
    vector<vector<int>> adj(n+1);
    while (e--) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<pair<int,int>> q;
    vector<bool> vis(n+1);
    vector<int> parent(n+1);
    q.push({1,0});
    vis[1] = 1;
    parent[1] = -1;

    while (!q.empty()) {
        auto [u,dis] = q.front(); 
        q.pop();

        if (u == n) {
            cout<<dis+1<<'\n';
            vector<int> path;
            int act = n;
            while (act != -1){
                path.push_back(act);
                act = parent[act];
            }
            reverse(path.begin(),path.end());
            for (auto c : path){
                cout<<c<<" ";
            }
            return 0;
        }
        
        for (int x : adj[u]) {
            if (vis[x]) continue;
            q.push({x,dis + 1});
            vis[x] = 1;
            parent[x] = u;
        }
    }
    
    cout<<"IMPOSSIBLE";

    return 0;
}