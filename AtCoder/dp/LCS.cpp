#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s,t; cin>>s>>t;
	int n = s.size() , m = t.size();
	vector<vector<int>> dp(n+1, vector<int> (m+1));

	for(int i = 1; i <= n ;i++) {
		for(int j = 1; j <= m ; j++) {
			if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	}

	string ans = "";

	int i = n, j = m;
	while(i != 0 && j != 0) {
		if (dp[i][j] == dp[i-1][j]) {
			i--;
		} else if (dp[i][j] == dp[i][j-1]){
			j--;
		}
		else {
			ans += s[i-1];
			i--; j--;
		}
	}

	reverse(ans.begin(), ans.end());
	cout<<ans;
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
