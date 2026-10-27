#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef queue<int> qi;
typedef queue<pii> qpii;
 
#define sz(x) ll(x.size())
#define fore(i,a,b) for(ll i = a; i<b; i++)
#define forr(x,v) for(auto& x : v)

#define cinv(vec,n) for(int i = 0; i<n; i++) cin>>vec[i];
#define coutv(vec,n) for(int i = 0; i<n; i++) cout<<vec[i]<<" ";
#define cin2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j]<<" "; j++);


#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()

#define fixed(n) fixed << setprecision(n)

void solve(){
    int n,m; cin>>n>>m;
    vvi adj(n+1); vb vis(n+1); qpii q;
    vi parent(n+1);
    while (m--) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    parent[1] = -1;
    bool fl = 0;
    auto bfs = [&](int x) {
        vis[x] = 1;
        q.push({x,0});

        while (!q.empty()) {
            auto [u,dist] = q.front();
            q.pop();
            if (u == n) {
                cout<<dist+1<<'\n';
                
                vi path; int cur = n;
                while (cur != -1) {
                    path.push_back(cur);
                    cur = parent[cur];
                }
                reverse(rall(path));
                forr(x,path) cout<<x<<" ";
                fl = 1;
                return;
            } 

            forr(x,adj[u]){
                if (vis[x]) continue;
                vis[x] = 1;
                q.push({x,dist+1});
                parent[x] = u;
            }
        }
    };
    bfs(1);
    if (!fl) cout<<"IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}