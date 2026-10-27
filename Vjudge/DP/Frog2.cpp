#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n,k; cin>>n>>k;
    vector<int> f(n+1);
    for (auto& x : f) cin>>x;

    vector<ll> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i-j >= 0) dp[i] = min(dp[i], dp[i-j] + abs(f[i]-f[i-j]));
        }
    }
    cout<<dp[n-1];   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}