#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> f(n+1);
    for (auto& x : f) cin>>x;

    vector<ll> dp(n+1);
    dp[0] = 0;
    dp[1] = abs(f[1]-f[0]);
    for (int i = 2; i <= n; i++) {
        dp[i] = min(abs(f[i] - f[i-2])+dp[i-2], abs(f[i] - f[i-1]) + dp[i-1]);
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