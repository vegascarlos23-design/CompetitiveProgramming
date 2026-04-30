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

pii target[256];
string ans = "123456789ABCDEF0";
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

struct Node {
    string s;
    int g,h;
    bool operator<(const Node &o) const{
        return g+h>o.g+o.h;
    }
};

int Manhattan(string &s) {
    int dist = 0;
    fore(i,0,16) {
        if (s[i] == '0') continue;
        int x = i/4, y = i%4;
        auto [tx,ty] = target[s[i]];
        dist += (abs(x - tx) + abs(y - ty));
    }
    return dist;
}

int Astar(string start) {
    priority_queue<Node> pq;
    map<string,int> dist;

    pq.push({start,0,Manhattan(start)});
    dist[start] = 0;

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();

        if (cur.s == ans) return cur.g;

        if (cur.g > dist[cur.s]) continue;

        int pos = cur.s.find('0');
        int x = pos/4, y = pos%4;

        fore(d,0,4) {
            int nx = x+dx[d];
            int ny = y+dy[d];

            if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
                int np = nx*4 + ny;
                string nxt = cur.s;

                swap(nxt[pos], nxt[np]);

                int ng = cur.g+1;
                if (!dist.count(nxt) || dist[nxt] > ng) {
                    dist[nxt] = ng;
                    pq.push({nxt,ng,Manhattan(nxt)});
                }
            }
        }
    }
    return -1;
}

void solve(){
    fore(i,0,16) target[ans[i]] = {i/4,i%4};
    string s = "";
    int x;
    fore(i,0,16) {
        cin>>x;
        if (x == 0) s += '0';
        else if (x < 10) s += char('0' + x);
        else s += char('A' + (x-10));
    }
    cout<<Astar(s)<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}