#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin>>n;
	vector<long long> a(n+1);

	long long s = 0;
	for(int i = 1; i<= n; i++) {
		cin>>a[i];
		s += a[i];
	}	

	vector<vector<long long>> dp(n+1, vector<long long>(n+1));
	for(int i = 1; i <= n; i++) {
		dp[i][i] = a[i];
	}
	
	for(int tam = 2; tam <= n ; tam++) {						
		for (int l = 1; l + tam - 1 <= n; l++) {
			int r = l + tam - 1;
			dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]); 
		}
	}

	long long ans = (s + dp[1][n]) / 2;
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
