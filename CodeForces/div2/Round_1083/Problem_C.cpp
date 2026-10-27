#include <bits/stdc++.h>

using namespace std;

#

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
#define F first
#define S second
#define pb push_back

#define fixed(n) fixed << setprecision(n)

void solve() {
    int n; cin>>n;
    vvi v(n);

    fore (i,0,n) {
        int l; cin>>l;
        vi a(l); cinv(a,l);
        unordered_set<int> se;
        for (int j = l-1; j >= 0; j--) {
            if (!se.count(a[j])) {
                v[i].pb(a[j]);
                se.insert(a[j]);
            }
        }
    }

    vi dd(n), ans;
    unordered_set<int> vis;

    fore(k,0,n) {
        int fl = -1;
        vi mxcur;

        fore (j,0,n) {
            if (dd[j]) continue;
            vi cur;
            for (auto &x : v[j]) {
                if (!vis.count(x)) cur.pb(x);
            }

            if (fl == -1 || cur < mxcur) {
                fl = j;
                mxcur = cur;
            }
        }

        for (auto &x : mxcur) {
            ans.pb(x);
            vis.insert(x);
        }
        dd[fl] = 1;
    }

    coutv(ans,ans.size());
    cout<<'\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	cin >> t;
	while(t--)  solve();
	return 0;
}

