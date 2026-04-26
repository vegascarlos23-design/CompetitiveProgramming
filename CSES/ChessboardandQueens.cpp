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

int Rows[9];
int Cols[9];
int Queens[9][9];
char G[9][9];


bool check(int r,int c) {
    if (Rows[r] || Cols[c]) {
        return 0;
    }
    fore(i,1,9) fore(j,1,9) {
        if (Queens[i][j]) {
            if (abs(r-i) == abs(c-j)) {
                return 0;
            }
        }
    }
    return 1;
}

int backtracking(int row) {
    if (row == 9) {
        return 1;
    }
    int ans = 0;
    fore(col,1,9) {
        if (G[row][col] == '*') {
            continue;
        }
        if (check(row,col)) {
            Rows[row] = 1;
            Cols[col] = 1;
            Queens[row][col] = 1;

            ans+= backtracking(row+1);

            Rows[row] = 0;
            Cols[col] = 0;
            Queens[row][col] = 0;
        }
    }
    return ans;
}
void solve(){
    fore(i,1,9) fore(j,1,9) {
        char x; cin>>x;
        G[i][j] = x;
    }
    cout<<backtracking(1);
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}