#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin>>n;
	vector<double> p(n+1);
	for(int i = 1; i <= n; i++) {
		cin>>p[i];
	}

	vector<vector<double>> dp(n+1, vector<double> (n+1));

	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < i; j++) {
			dp[i][j] += dp[i-1][j] * (1-p[i]);
		       	dp[i][j+1] += dp[i-1][j] * p[i];	
		}
	}

	double ans = 0;

	for(int j = n/2 + 1; j <= n ; j++) {
		ans += dp[n][j];
	}	

	cout<< fixed << setprecision(10) << ans;
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
