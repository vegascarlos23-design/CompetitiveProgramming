#include <stdio.h>

#define INF 1000000000

int min(int a, int b) {
    return (a < b ? a : b);
}

void solve() {
	int n; scanf("%d", &n);

	int adj[n+1][n+1];
	for(int i = 0; i <= n ; i++) {
		for(int j = 0; j <= n; j++) {
			if (i == j) {
				adj[i][j] = 0;
				continue;
			}
			scanf("%d", &adj[i][j]);
		}
	}

	int dp[1<<(n+1)][n+1];
	for(int mask = 0; mask < (1<<(n+1)); mask++) {
        for(int u = 0; u < n+1; u++) {
            dp[mask][u] = INF;
        }
    }

	dp[0][0] = 0;
	
	for(int mask = 0; mask < (1 << (n+1)) ; mask++) {
		for(int u = 0; u < n+1 ; u++) {
			if (dp[mask][u] == INF) continue;

			for(int v = 0; v < n+1; v++) {
				if (adj[u][v] == 0 || (mask & (1<<v))) continue;
				
				dp[mask | (1<<v)][v] = min(dp[mask | (1<<v)][v], dp[mask][u] + adj[u][v]);	
			}
		}
	}
	int ans = INF;
	for(int u = 0; u < n+1; u++) {
		ans = min(ans, dp[(1<<(n+1)) - 1][u] + adj[u][0]);
	}
	printf("%d\n", ans);
}

int main() {
	int t = 1;
	scanf("%d", &t);
	while(t--) {
		solve();
	}

	return 0;
}
