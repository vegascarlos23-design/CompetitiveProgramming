#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

void solve() {
	int n,q; cin>>n>>q;

	vector<vector<int>> adj(n, vector<int>(n));

	while(q--) {
		int u,v; cin>>u>>v;
		u--; v--;
		adj[u][v]++;
	}

	vector<vector<int>> dp( (1<<n), vector<int>(n));

	dp[1][0] = 1;

	for(int mask = 0; mask < (1 << n); mask++) {
		for(int u = 0; u < n; u++) {
			if (dp[mask][u] == 0) continue;

			for(int v = 0; v < n; v++) {
				if (!adj[u][v] || mask & (1<<v)) continue;

				dp[mask | (1<<v)][v] = ( dp[mask | (1<<v)][v] + (1LL * dp[mask][u] * adj[u][v]) % MOD ) % MOD;
			}
		}
	}

	cout<<dp[ (1<<n) - 1 ][n-1];
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
