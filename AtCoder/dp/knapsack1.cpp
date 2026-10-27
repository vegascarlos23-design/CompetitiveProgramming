
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n,w; cin>>n>>w;
	vector<long long> weights(n+1), gain(n+1);

	for(int i = 1; i <= n; i++) {
		int wx, vx; cin>>wx>>vx;

		weights[i] = wx; gain[i] = vx;
	}

	vector<vector<long long>> dp(w+1, vector<long long> (n+1));

	for(int wi = 0; wi <= w; wi++) {
		for(int i = 1; i <= n; i++) {
			dp[wi][i] = dp[wi][i-1];
			if (wi - weights[i] >= 0) {
				dp[wi][i] = max(dp[wi][i-1] , dp[wi - weights[i]][i-1] + gain[i]);
			}
		}
	}

	cout<<dp[w][n];

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
