#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k; cin>>n>>k;
	vector<int> weight(n+1), gain(n+1);
	for(int i = 1; i<n+1; i++) {
		cin>>weight[i];
	}
	for(int i = 1; i<n+1; i++) {
		cin>>gain[i];
	}

	vector<vector<int>> dp(n+1, vector<int> (k+1));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if (j - weight[i] >= 0) {
				dp[i][j] = dp[i-1][j-weight[i]] + gain[i]; 
			}
			dp[i][j] = max(dp[i][j] , dp[i-1][j]); 
		}	
	}

	cout<<dp[n][k];

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}
