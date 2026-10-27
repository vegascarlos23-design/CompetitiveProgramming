#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n,k; cin>>n>>k;
    vector<int> c(n);
    for (auto& x : c) cin>>x;

    vector<ll> dp(k+1, INT_MAX);
    
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        for (auto& x : c) {
            if (i-x >= 0) dp[i] = min(dp[i], dp[i-x] + 1);
        }
    }
    
    cout<< (dp[k] == INT_MAX ? -1 : dp[k]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}