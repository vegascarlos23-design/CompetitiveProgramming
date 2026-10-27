#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k; cin>>n>>k;
	vector<int> a(n);
	for(int i = 0; i<n; i++) {
		cin>>a[i];
	}
	
	vector<vector<bool>> dp(501, vector<bool> (501));

	dp[0][0] = 1;

	for(auto c: a) {
		for(int j = k; j >= 0; j--) {
			for(int x = k ; x >= 0; x--) {
				if (!dp[j][x]) continue;
				if (j+c <= k) {
					dp[j+c][x] = 1;
				}	

				if (j+c <= k && x + c <= k) {
					dp[j+c][x+c] = 1;
				}	
			} 
		}
	}
	
	vector<int> ans;
	for (int i = 0; i<501; i++) {
		if (dp[k][i]) ans.push_back(i);
	}

	cout<<ans.size()<<endl;

	for(auto x : ans) {
		cout<<x<<" ";
	}

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
