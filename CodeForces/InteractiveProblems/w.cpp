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
    int x,y,z,a,b;
    cout<<1<<" "<<0<<" "<<0 << endl;
    cout.flush();
    cin>>x;
    cout<<0<<" "<<1<<" "<<0 << endl;
    cout.flush();
    cin>>y;
    cout<<0<<" "<<0<<" "<<1 << endl;
    cout.flush();
    cin>>z;
    cout<<1<<" "<<1<<" "<<1 << endl;
    cout.flush();
    cin>>a;
    cout<<1<<" "<<2<<" "<<3 << endl;
    cout.flush();
    cin>>b;

    if (x+y+z == a || x+2*y+3*z == b) {
        cout<<x<<" "<<y<<" "<<z << endl;
        cout.flush();
        return;
    }
    int px,py,pz;
    px = a-y-z; py = a-x-z; pz = a-x-y;
    if (px + 2*y + 3*z == b) {
        cout<<px<<" "<<y<<" "<<z << endl;
        cout.flush();
        return;
    }
    if (x + 2*py + 3*z == b) {
        cout<<x<<" "<<py<<" "<<z << endl;
        cout.flush();
        return;
    }
    if (x + 2*y + 3*pz == b) {
        cout<<x<<" "<<y<<" "<<pz << endl;
        cout.flush();
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