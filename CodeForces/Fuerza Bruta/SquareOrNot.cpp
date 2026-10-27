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
            int n; cin>>n;
            string s; cin>>s;
            int r = sqrt(n);
            if (r*r != n){
                cout<<"No"<<'\n';
                return;
            }
            int cur = 0;
            fore(i,0,r) {
                if (i == 0 || i == r-1) {
                    fore(j,cur,cur + r) {
                        if (s[j] != '1') {
                            cout<<"No"<<'\n';
                            return;
                        }
                    }
                    cur += r;
                }
                else {
                    if (s[cur] != '1' || s[cur + r - 1] != '1') {
                        cout<<"No"<<'\n';
                        return;
                    }
                    fore(k,cur + 1,cur + r - 1){
                        if (s[k] != '0') {
                            cout<<"No"<<'\n';
                            return;
                        }
                    }
                    cur += r;
                }
            }
            cout<<"Yes"<<'\n';
        }

        int main() {
            ios::sync_with_stdio(0);
            cin.tie(0);
            
            int t = 1; 
            cin >> t;
            while(t--)  solve();
            return 0;
        }