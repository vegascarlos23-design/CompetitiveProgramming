#include <bits/stdc++.h>

using namespace std;
const int NEG = -1e9;
const int MAX5 = 25 * 200;


int v2(long long x) {
	int c = 0;
	while(x % 2 == 0) {
		c++;
		x /= 2;
	}
	return c;
}

int v5(long long x) {
	int c = 0;
	while(x % 5 == 0) {
		c++;
		x /= 5;
	}
	return c;
}

void solve(){
	int n, k; cin>>n>>k;

	vector<long long> a(n);
	for(auto &x : a) cin>>x;

	vector<vector<int>> dp(k+1, vector<int>(MAX5 + 1, NEG));
	dp[0][0] = 0;
	vector<vector<int>> ndp;

	for(int i = 0; i < n; i++) {
		int two = v2(a[i]);
		int five = v5(a[i]);
		ndp = dp;
		for(int j = 0; j <= k; j++) {
			for(int l = 0; l <= MAX5; l++) {
				if (dp[j][l] == NEG) continue;

				ndp[j][l] = max(ndp[j][l], dp[j][l]);
				if (l + five <= MAX5 && j < k) 
					ndp[j + 1][l + five] = max(ndp[j + 1][l + five] , dp[j][l] + two);
			}
		}
		dp = ndp;
	}
	
	int ans = 0;

	for(int i = 0; i<= MAX5; i++) {
		ans = max(ans, min(i, ndp[k][i]));
	}

	cout<<ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	//cin >> t;
	while(t--)  solve();
	return 0;
}
