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

bool check(string s) {
    bool fl = 0;
    map<char,int> mp;
    for (char &c : s) {
        mp[c]++;
    }

    for(auto &x : mp) {
        if (x.second & 1) {
            if (fl || (n & 1) == 0) return 0;
            fl = 1;
        }
    }

    return true;
}

void solve(){ 
    string s; cin>>s;
    n = s.size();
    if(check(s)) {
        map<char,int> mp;
        for (char &c : s) {
            mp[c]++;
        }
        string ans;
        char imp = ' ';
        for(auto &x : mp) {
            if (x.second & 1) {
                imp = x.first;
            } else {
                ans.append(x.second/2,x.first);  
            }
                     
        }
        string rans = ans;
        reverse(all(rans));
        ans.append(mp[imp],imp);
        
        ans += rans;
        cout<<ans;
    } else cout<<"NO SOLUTION";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}