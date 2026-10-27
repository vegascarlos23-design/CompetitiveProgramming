#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,x; cin>>n>>x;
	vector<long long> coins(n);

	for(int i = 0;i < n ;i++) {
		cin>>coins[i];
	}

	vector<long long> dp(x+1, INT_MAX);
	dp[0] = 0;

	for(int i = 1; i < x+1; i++) {
		for(auto c : coins) {
			if (i-c >= 0) dp[i] = min (dp[i], dp[i-c] + 1);
		}	

	}
	
	cout<< (dp[x] == INT_MAX ? -1 : dp[x]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
