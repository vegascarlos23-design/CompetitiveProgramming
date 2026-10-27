#include <bits/stdc++.h>

using namespace std;
const long long INF = 1e18;

void solve(){
	int n; cin>>n;
	vector<long long> v(n+1);
       	for(int i = 1; i<= n; i++) {
		cin>>v[i];
	}	

	vector<vector<long long>> dp(n+1, vector<long long> (2, INF));
	
	dp[0][1] = 0;

	for(int i = 0; i< n; i++) {
		if (dp[i][1] != INF) {
			dp[i+1][0] = min(dp[i+1][0], dp[i][1] + v[i+1]);
			if (i+2 <= n) dp[i+2][0] = min(dp[i+2][0], dp[i][1] + v[i+1] + v[i+2]); 
		}

		if (dp[i][0] != INF) {
			dp[i+1][1] = min(dp[i+1][1], dp[i][0]);
			if (i+2 <= n) dp[i+2][1] = min (dp[i+2][1], dp[i][0]);
		}
	}	

	cout<<min(dp[n][0], dp[n][1])<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	cin >> t;
	while(t--)  solve();
	return 0;
}
