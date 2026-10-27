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
    vvc G (n,vc(m));
    vvb vis(n,vb(m));
    cin2d(G,n,m);

    vi Ex = {-1,1,0,0};
    vi Ey = {0,0,-1,1};

    function<void(int,int)> dfs = [&](int x, int y) {
        vis[x][y] = 1;
        fore(i,0,4){
            int dx = x + Ex[i];
            int dy = y + Ey[i];

            if (dx >= 0 && dx < n && dy >= 0 && dy < m && G[dx][dy] == '.' && !vis[dx][dy]) {
                dfs(dx,dy);
            }
        }
    };
    int c = 0;
    fore(i,0,n) {
        fore(j,0,m){
            if (G[i][j] == '#' || vis[i][j]) continue;
            dfs(i,j);
            c++;
        }
    }
    cout<<c;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}