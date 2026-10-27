#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

int N = 1e6 + 1;
vector<vector<long long>> dp(N, vector<long long> (2));

void preCompute() {
	dp[1][0] = 1;
	dp[1][1] = 1;

	for(int i = 2; i < N; i++) {
		dp[i][0] = (( 4 * dp[i-1][0]%MOD ) % MOD + dp[i-1][1]%MOD ) % MOD;
		dp[i][1] = (( 2 * dp[i-1][1]%MOD ) % MOD + dp[i-1][0]%MOD ) % MOD;	
	}
}

void solve() {	
	int n; cin>>n;
	cout<< (dp[n][0]%MOD + dp[n][1]%MOD) % MOD <<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	preCompute();
	int t = 1;
	cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}
