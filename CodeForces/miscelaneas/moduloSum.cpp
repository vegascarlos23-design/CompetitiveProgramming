#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, m; cin>>n>>m;

	if (n > m) {
		cout<<"YES";
		return;
	}

	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}

	vector<vector<bool>> dp(n+1, vector<bool> (m));

	for(int i = 0; i < n; i++) {
		dp[i+1] = dp[i];

		dp[i+1][a[i] % m] = 1;

		for(int r = 0; r < m; r++) {
			if (dp[i][r]) {
				dp[i+1][(r + a[i]) % m] = 1;
			}
		}
	}

	cout<< (dp[n][0] == 1 ? "YES" : "NO");
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	//cin >> t;
	while(t--)  solve();
	return 0;
}
