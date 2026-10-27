#include <bits/stdc++.h>

using namespace std;
const long long INF = 4e18;
const long long NEG = -4e18;

struct Vaca {
	long long altura;
	long long peso;
	long long fuerza;
};

void solve() {
	long long n,h; cin>>n>>h;
	vector<Vaca> cows(n);

	for(int i = 0; i < n; i++) {
		cin >> cows[i].altura >> cows[i].peso >> cows[i].fuerza;
	}

	vector<long long> dp(1<<n , NEG), weight(1<<n), height(1<<n);
	dp[0] = INF;
	
	for(int mask = 0; mask < (1<<n) ; mask++) {
		if (dp[mask] == NEG) continue;
		for(int i = 0; i < n; i++) {
			if (mask & (1<<i)) continue;
			weight[mask | (1<<i)] = weight[mask] + cows[i].peso;
			height[mask | (1<<i)] = height[mask] + cows[i].altura;

			dp[mask | (1<<i)] = max(dp[mask | (1<<i)] , min(dp[mask], cows[i].fuerza - weight[mask]));
		}
	}

	long long ans = -1;
	for(int mask = 0; mask < (1<<n) ; mask++) {
		if (height[mask] >= h) {
			ans = max(ans, dp[mask]);
		}
	}

	if (ans == -1) {
		cout<<"Mark is too tall";
	} else {
		cout<<ans;
	}
}

int main() {
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}
