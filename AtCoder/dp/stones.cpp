#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k; cin>>n>>k;

	vector<int> a(n); for(auto &x : a) cin>>x;

	vector<bool> dp(k+1);
	dp[0] = 0;

	for(int i = 1; i <= k; i++) {
		for(auto &x : a) {
			if (i - x >= 0 && !dp[i - x]) {
				dp[i] = 1;
				break;
			}	
		}
	}
	
	cout<< (dp[k] ? "First" : "Second");
	
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
