#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n,k; cin>>n>>k;
	vector<int> v(n);

	for(int i = 0; i < n; i++) cin>>v[i];

	vector<long long> dp(n+1);

	for(int i = 1; i<k; i++) {
		dp[i] = abs(v[i] - v[0]); 
	}
	
	for(int i = k; i < n; i++) {
		dp[i] = INT_MAX;
		for(int j = 1; j < k+1; j++) {
			dp[i] = min(dp[i], dp[i - j] + abs(v[i-j] - v[i]));
		}	
	}

	cout<<dp[n-1];
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
