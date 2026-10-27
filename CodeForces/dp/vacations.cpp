#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin>>n;
	vector<vector<int>> v(n,vector<int>(2));

	for(int i = 0; i < n; i++) {
		int x; cin>>x;
		if (x == 0) {v[i][0] = 0; v[i][1] = 0;}
		else if (x == 1) {v[i][0] = 0; v[i][1] = 1;}
		else if (x == 2) {v[i][0] = 1; v[i][1] = 0;}
		else {v[i][0] = 1; v[i][1] = 1;}
	}	

	/*for(int i = 0; i < n; i++) {
		cout<<v[i][0] << " " << v[i][1]<<'\n';
	}*/

	vector<vector<int>> dp(n+1, vector<int>(2));
	
	for(int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i-1][0] + 1, dp[i-1][1] + !(v[i-1][1]));
		dp[i][1] = min(dp[i-1][0] + !(v[i-1][0]), dp[i-1][1] + 1);
		
		//cout<<dp[i][0]<<" " <<dp[i][1]<<'\n';
	}

	cout<<min(dp[n][0], dp[n][1]);
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
