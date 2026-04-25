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

int n;
vvi G;
vvi Rows;
vvi Cols;
vector<vector<vector<int>>> SG;

bool check(int num, int r, int c) {
    if (Rows[r][num] || Cols[c][num] || SG[((r-1)/n)+1][((c-1)/n)+1][num]) {
        return 0;
    }
    return 1;
}

bool backtracking(int row, int col) {
    if (row == n*n + 1) return 1; 

    int nextRow = row, nextCol = col+1;
    if (nextCol == n*n + 1) {
        nextCol = 1;
        nextRow++;
    }

    if (G[row][col] != 0) {
        return backtracking(nextRow, nextCol);
    } 
    else {
        fore(num,1,10) {
            if (check(num, row, col)) {
                G[row][col] = num;
                Rows[row][num] = 1;
                Cols[col][num] = 1;
                SG[((row-1)/n)+1][((col-1)/n)+1][num] = 1;

                if (backtracking(nextRow, nextCol)) return 1;

                G[row][col] = 0;
                Rows[row][num] = 0;
                Cols[col][num] = 0;
                SG[((row-1)/n)+1][((col-1)/n)+1][num] = 0;
            }
        }
    }
    return 0;
}

void solve() {
    G.assign(n*n + 1, vi(n*n + 1));
    Rows.assign(n*n + 1, vi(n*n + 1));
    Cols.assign(n*n + 1, vi(n*n + 1));
    SG.assign(n+1, vvi(n+1, vi(n*n + 1)));

    int x;
    fore(i,1,n*n+ 1) fore(j,1,n*n+1) {
        cin>>x;
        G[i][j] = x;
        
        Rows[i][x] = 1;
        Cols[j][x] = 1;
        SG[((i-1)/n)+1][((j-1)/n) +1][x] = 1;       
    }
    bool ok = backtracking(1,1);

    if (!ok) {
        cout <<"NO SOLUTION\n";
    } else {
        fore(i,1,n*n+1) {
            fore(j,1,n*n+1) {                
                cout << G[i][j];
                if (j < n*n) cout<<" ";
            }
            cout<<'\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool first = 1;

    while (cin>>n) {
        if (!first) cout << '\n';
        first = 0;
        solve();
    }      
    return 0;
}