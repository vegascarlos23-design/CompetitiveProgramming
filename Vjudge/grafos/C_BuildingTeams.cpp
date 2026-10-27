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
    
    vector<bool> vis(n+1);
    vector<int> team(n+1);
    queue<int> q;

    auto bfs = [&](int x){
        vis[x] = 1;
        team[x] = 1;
        q.push(x);

        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (int c : adj[f]) {
                if (vis[c]) {
                    if (team[c] == team[f]) {
                        cout << "IMPOSSIBLE";
                        exit(0);
                    }   continue;
                }
                vis[c] = true;
                team[c] = 3 - team[f];
                q.push(c);       
            }
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) bfs(i);
    }
    for (int i = 1; i <= n; i++) {
        cout<<team[i]<<" ";
    }
    return 0;
}