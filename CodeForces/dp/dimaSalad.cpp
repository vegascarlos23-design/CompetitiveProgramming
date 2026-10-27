#include <bits/stdc++.h>

using namespace std;
	
const int off = 99900;
const int neg = -1e9;

void solve() {
	int n,k; cin>>n>>k;

	vector<int> a(n),c(n);
	for(auto &x : a) cin>>x;

	for(int i = 0; i < n; i++) {
		int x; cin>>x;
		c[i] = a[i] - x*k;
	}

	vector<vector<int>> dp(n+1,vector<int>(108901, neg));
	dp[0][off] = 0;

	for (int i = 1; i < n+1; i++) {
		for(int s = -99900; s < 9001; s++) {
			dp[i][s + off] = dp[i-1][s + off];

			int pre = s - c[i-1];
			if (pre >= -99900 && pre <= 9000 && dp[i-1][pre + off] != neg) {
				dp[i][s + off] = max(dp[i][s + off], dp[i-1][pre + off] + a[i-1]);
			}
		}
	}
	int ans = dp[n][off];

	cout<< (ans <= 0 ? -1 : ans) << '\n';
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
