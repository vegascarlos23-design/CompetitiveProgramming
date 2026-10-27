#include <bits/stdc++.h>
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
    int n,mx = -1; cin>>n;
    vll pt;
    map<int, vi> mp;

    fore(i,1,n+1){
        cout<<"? "<<i<<" "<<n;
        fore(j,1,n+1){
            cout<<" "<<j;
        }
        cout<<endl;
        cout.flush();

        int cur; cin>>cur;

        mp[cur].push_back(i);

        if (cur > mx) {
            mx = cur;
            pt = {i};
        }
    }

    for(ll i = mx -1; i>0; i--){
        forr(x,mp[i]){
            cout<<"? "<<pt.back()<<" 2 "<<pt.back()<<" "<<x;
            cout<<endl;
            cout.flush();

            int k; cin>>k;

            if(k == 2) {
                pt.push_back(x);
                break;
            }
        }
    }
    cout<<"! "<<pt.size();
    forr(x,pt) cout<<" "<<x;
    cout<<endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}