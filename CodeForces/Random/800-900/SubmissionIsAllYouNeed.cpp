#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> v(n);
    for (auto& x : v) cin>>x;
    int sum = 0;
    bool fl = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) fl = 1;
        if (v[i] + 1 == v[i+1] && fl && v[i+1] <= 1) continue;
        else if (fl) {
            sum += v[i] + 1;
            fl = 0;
            continue;
        }
        sum += v[i];
        
    }
    cout<<sum<<'\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}