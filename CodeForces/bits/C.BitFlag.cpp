#include <bits/stdc++.h>

using namespace std;

#ifdef ONLINE_JUDGE
#define dbg(...) 42
#else
#include "dbg/debug.h"
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
    uint64_t mask = 0;
    int q; cin>>q;
    while (q--) {
        int x,i=0; cin>>x;
        int c = 0;
        if(x<4) {
            cin>>i;
        }

        switch (x) {
        case 0:
            cout<<((mask>>i)&1ULL);
            cout<<'\n';
            break;
        case 1:
            mask |= (1ULL<<i);
            break;
        case 2:
            mask &= ~(1ULL<<i);
            break;
        case 3:
            mask ^= (1ULL<<i);
            break;
        case 4:
            if (mask == ~0ULL) cout<<1;
            else cout<<0;
            cout<<'\n';
            break;
        case 5:
            if (mask != 0) cout<<1;
            else cout<<0;
            cout<<'\n';
            break;
        case 6:
            if (mask == 0) cout<<1;
            else cout<<0;
            cout<<'\n';
            break;
        case 7:
            fore(i,0,64){
                if(((mask>>i)&1) == 1) c++;
            }
            cout<<c;
            cout<<'\n';
            break;            
        default:
            cout<<mask;
            cout<<'\n';
            break;
        }
        
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