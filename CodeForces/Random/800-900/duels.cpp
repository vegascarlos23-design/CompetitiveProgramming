#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    bool c = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    
    for (int i = 0; i < n-1; i++)
    {
        if ((v[i] + v[i+1] == 0))   {
            cout<<"YES"<<'\n';
            return;
        }
        if (v[i] == 0 || v[i+1] == 0)   {
            c = 1;
        }  
    }
    cout<<(c ? "NO" : "YES")<<'\n';
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}