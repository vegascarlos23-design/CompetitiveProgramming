#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> dp(n+1, INT_MAX);

	dp[0] = 0;
	
	for(int i = 1; i < n+1; i++) {
		vector<int> dig; int x = i;
		while(x > 0) {
			dig.push_back(x%10);
			x /= 10;
		}
		
		for(auto d : dig) {
			if (d != 0 && i - d >= 0) dp[i] = min(dp[i], dp[i-d] + 1);
		}
	}	
	
	cout<<dp[n];
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
