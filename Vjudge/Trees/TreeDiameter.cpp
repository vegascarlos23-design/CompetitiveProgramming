#include <bits/stdc++.h>

using namespace std;

#ifdef ONLINE_JUDGE
#define dbg(...) 42
#else
//#include "dbg/debug.h"
#endif

using namespace std;

long long inf = 1e18;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<pair<ll,ll>>> vvp;
typedef vector<vector<long long>> vvll;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
typedef queue<int> qi;
typedef queue<pii> qpii;
 
#define sz(x) ll(x.size())
#define fore(i,a,b) for(ll i = a; i<b; i++)
#define forr(x,v) for(auto& x : v)
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define cinv(vec,n) for(int i = 0; i<n; i++) cin>>vec[i];
#define coutv(vec,n) for(int i = 0; i<n; i++) cout<<vec[i]<<" ";
#define cin2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j]<<" "; j++);


#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()

#define fixed(n) fixed << setprecision(n)

int n;
vvi adj;

pii bfs(int start) {
    vi dist(n+1,-1);
    qi q;

    dist[start] = 0;
    int far = start;
    q.push(start);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &x : adj[u]) {
            if (dist[x] == -1) {
                dist[x] = dist[u] + 1;
                q.push(x);
                if (dist[x] > dist[far]) {
                    far = x;
                }
            }
        }
    }
    return {far, dist[far]};
}

void solve(){
    cin>>n;
    adj.assign(n+1,{});

    fore(i,0,n-1) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto [A,_] = bfs(1);
    auto [B,diametro] = bfs(A);
    cout<<diametro;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}