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

void solve(){
    string s = "";
    fore(i,0,9) {
        char c; cin>>c;
        s+= c;
    }
    string ans = "123456780";
    vvi moves = {{1,3},{0,2,4},{1,5},{0,4,6},{1,3,5,7},{2,4,8},{3,7},{4,6,8},{5,7}};

    queue<string> q;
    map<string, int> dist;
    q.push(s);

    while(!q.empty()) {
        string cur = q.front(); q.pop();

        if (cur == ans) {
            cout<<dist[cur]<<'\n';
            return;
        }

        int idx = cur.find('0');
        for(auto& nxtPos : moves[idx]) {
            string nxtS = cur;
            swap(nxtS[idx], nxtS[nxtPos]);

            if (!dist.count(nxtS)) {
                dist[nxtS] = dist[cur] +1;
                q.push(nxtS);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}