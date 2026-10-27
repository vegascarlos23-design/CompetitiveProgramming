#include <bits/stdc++.h>

using namespace std;

#ifdef ONLINE_JUDGE
#define dbg(...) 42
#else
//#include "dbg/debug.h"
#endif

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
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

#define cinv(vec,n) for(int i = 0; i<n; i++) cin>>vec[i];
#define coutv(vec,n) for(int i = 0; i<n; i++) cout<<vec[i]<<" ";
#define cin2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout2d(vec, n, m) for(int i = 0; i < n; i++, cout << "\n") for(int j = 0; j < m && cout << vec[i][j]<<" "; j++);


#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()

#define fixed(n) fixed << setprecision(n)

const ll MOD = 1e9 + 7;

void solve(){
    int n,m; cin>>n>>m;
    vi v(n);
    vvll dp(n,vll(m+2));
    cinv(v,n);
    
    fore(i,0,n){
        if (i == 0){
            if(v[0] == 0) fore(j,1,m+1) dp[0][j] = 1;                
            else dp[0][v[0]] = 1;
        }
        else {
            if(v[i] == 0) fore(j,1,m+1) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%MOD;                
            else dp[i][v[i]] = (dp[i-1][v[i] - 1] + dp[i-1][v[i]] + dp[i-1][v[i] + 1])%MOD;
        }        
    }
    ll ans = 0;
    fore(i,1,m+1) ans = (ans + dp[n-1][i])%MOD;
    cout<<ans;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}