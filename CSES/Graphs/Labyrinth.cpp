#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
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

#define cinv(vec,n) for(int i = 0; i<n; i++) cin>>vec[i];
#define coutv(vec,n) for(int i = 0; i<n; i++) cout<<vec[i]<<" ";
#define cin2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j]<<" "; j++);


#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()

#define fixed(n) fixed << setprecision(n)

void solve(){
    int n,m; cin>>n>>m;
    vvc G(n,vc(m));
    vvb vis(n,vb(m));
    qpii q;
    vector<vector<pii>> parent(n, vector<pii>(m, {-1,-1}));
    cin2d(G,n,m);
    vi Ex = {-1,1,0,0};
    vi Ey = {0,0,-1,1};
    
    pii A = {-1,-1};
    fore(i,0,n) fore(j,0,m){
        if (G[i][j] == 'A') {
            A = {i,j};
        }
    }

    bool fl = 0;
    function<void(int, int)> Bfs = [&](int x, int y){
        vis[x][y] = 1;
        q.push({x,y});
        while (!q.empty()) {
            auto [a,b] = q.front(); 
            q.pop();
            if (G[a][b] == 'B') {
                cout<<"YES"<<'\n';
                vc path;
                pii cur = {a,b};
                while (cur != A) {
                    int difx = cur.first - parent[cur.first][cur.second].first;
                    int dify = cur.second - parent[cur.first][cur.second].second;
                    if (difx == 0 && dify == -1) path.push_back('L');                    
                    else if (difx == 0 && dify == 1)path.push_back('R');   
                    else if (difx == 1 && dify == 0) path.push_back('D');
                    else if (difx == -1 && dify == 0) path.push_back('U');
                    cur = parent[cur.first][cur.second];
                }
                reverse(rall(path));
                cout<<path.size()<<'\n';
                forr(x,path) cout<<x;
                fl = 1;
                return;
            }
            // cout<<a<<" "<<b<<'\n';
            fore(i,0,4){
                int dx = Ex[i] + a;
                int dy = Ey[i] + b;
                if (dx >= 0 && dx < n && dy >= 0 && dy < m && (G[dx][dy] == '.' || (G[dx][dy] == 'B')) && !vis[dx][dy]){
                    vis[dx][dy] = 1;
                    q.push({dx,dy});
                    parent[dx][dy] = {a,b};
                }
            }
        } 
    };
    Bfs(A.first,A.second);
    if(!fl){
        cout<<"NO";
        return;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}