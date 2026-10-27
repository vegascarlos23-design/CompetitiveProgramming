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

void solve(){
    ll x1, y1, x2, y2, x3, y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    
    ll ans = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
    
    if (ans == 0) {
        cout<<"TOUCH";
    } 
    else if (ans > 0) {
        cout<<"LEFT";
    }
    else if (ans < 0 ) {
        cout<<"RIGHT";
    }
    cout<<'\n';
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}