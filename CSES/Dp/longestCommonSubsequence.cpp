#include <bits/stdc++.h>

using namespace std;

void solve() {	
	int n,m; cin>>n>>m;
	vector<long long> v1(n+1),v2(m+1);

	for(int i = 1; i <= n; i++) cin>>v1[i];

	for(int i = 1; i <= m; i++) cin>>v2[i];

	vector<vector<int>> dp(n+1, vector<int>(m+1));


	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
		if (v1[i] == v2[j]) dp[i][j] = dp[i-1][j-1] + 1;
		else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
	}
	/*
	for(int i = 1 ; i <= n; i++) { 
		for(int j = 1 ; j <= m; j++) {
			cout<<dp[i][j]<<" ";
		}	
		cout<<endl;
	}
	*/
	vector<long long> ans;
	
	int i = n, j = m; 
	while(i != 0 && j != 0) {
		if (dp[i][j] == dp[i-1][j]) i--;
		else if (dp[i][j] == dp[i][j-1]) j--;
		else {
			ans.push_back(v1[i]);
			i--; j--;
		}
	}
	
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(int idx = 0; idx < ans.size(); idx++) {
		cout<<ans[idx]<<" ";
	}
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
