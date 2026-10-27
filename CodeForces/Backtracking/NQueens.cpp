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

bool check(int fila,int col, vi& queens){
    fore(i,0,fila){
        if (queens[i] == col) return 0;
        if (abs(i-fila) == abs(queens[i]-col)) return 0;
    }
    return 1;
}

int backtracking(int fila, vi& queens,int n){
    if (fila == n){
        return 1;
    }
    int c = 0;
    fore(col,0,n){
        if (check(fila,col,queens)){
            queens.push_back(col);
            c += backtracking(fila+1,queens,n);
            queens.pop_back();
        }
    }
    return c;
}

void solve(){
    int n; cin>>n;
    vi queens;
    cout<<backtracking(0,queens,n);
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}