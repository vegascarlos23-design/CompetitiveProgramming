#include <bits/stdc++.h>

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
#define coutv(vec,n) for(int i = 0; i<n; i++) cout<<vec[i]<<' ';
#define cin2d(vec, n, m) for(int i = 0; i < n; i++) for(int j = 0; j < m && cin >> vec[i][j]; j++);
#define cout2d(vec, n, m) for(int i = 0; i < n; i++, cout << endl) for(int j = 0; j < m && cout << vec[i][j]<<' '; j++);

#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define F first
#define S second
#define pb push_back

#define fixed(n) fixed << setprecision(n)
int t,n,fl;
vi v,cur;

void backtracking(int pos,int sum) {
    if (sum > t) return;
    if (sum == t) {   
        fl = 1;             
        fore(i,0,cur.size()) cout<<cur[i]<<"+\n"[i+1==cur.size()];
        return;
    }

    fore(i,pos,n) {
        if (i > pos && v[i]==v[i-1]) continue;
        cur.pb(v[i]);
        backtracking(i+1,sum+v[i]);
        cur.pop_back();
    }
}

void solve(){
    cin>>n;
    fl = 0;
    v.assign(n,0);
    cinv(v,n);
    cout<<"Sums of "<<t<<":\n";
    backtracking(0,0);
    if (!fl) cout<<"NONE"<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t != 0) {
        solve();
        cin>>t;
    }
    return 0;
}