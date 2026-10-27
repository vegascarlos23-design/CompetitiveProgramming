#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<vector<int>> adj(n+1);
    vector<int> temp(n+1);
    for (int i = 1; i <= n; i++){
        cin>>temp[i];
    }
    for (int i = 1; i <= n; i++) {
        if (temp[i] != -1) {
            adj[temp[i]].push_back(i); 
        }
    }

    vector<bool> vis(n+1);
    vector<int> level(n + 1, -1);
    queue<int> q;
    int max_level = 0;

    auto bfs = [&](int x) {
        vis[x] = 1;
        level[x] = 0;
        q.push(x);

        while (!q.empty()) {
            int f = q.front();
            q.pop();
                for (int c : adj[f])
                {
                    if (vis[c]) continue;
                    vis[c] = 1;
                    level[c] = level[f] + 1;
                    max_level = max(max_level,level[c]);
                    q.push(c);
                }
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (temp[i] == -1) bfs(i);
    }
    cout<<max_level+1;
    return 0;
}