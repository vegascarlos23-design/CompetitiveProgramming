#include <bits/stdc++.h>
#define ll long long
const int MOD = 1e9+7;
using namespace std;

void solve(){
    int n,k; cin>>n>>k;
    vector<vector<char>> grid(n,vector<char>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(k));
    dp[0][0] = (grid[0][0] == '.' ? 1 : 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (i == 0 && j == 0) continue;
            if (grid[i][j] == '#'){
                dp[i][j] = 0;
                continue;
            } 
            if (i-1>=0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j-1>=0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }
    cout<<dp[n-1][k-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}