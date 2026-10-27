#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n; cin>>n;
	string s; cin>>s;

	vector<long long> X(n), Y(n-1);
	
	for(int i = 0; i<n; i++) {
		cin>>X[i];
	}

	for(int i = 0; i<n-1; i++) {
		cin>>Y[i];
	}
	vector<long long> costS(n) , costR(n);
	vector<vector<long long>> dp(n+1, vector<long long>(2));

	for(int i = 0; i < n ; i++) {
		costS[i] = (s[i] == 'S' ? 0 : -X[i]);
		costR[i] = (s[i] == 'R' ? 0 : -X[i]);
	}

    dp[0][0] = costS[0];
    dp[0][1] = costR[0];

	for(int i = 1; i < n+1 ; i++) {
		dp[i][0] = costS[i] + max(dp[i-1][0], dp[i-1][1]+Y[i-1]);
	
		dp[i][1] = costR[i] + max(dp[i-1][0] , dp[i-1][1]);
	}

	cout<< max(dp[n-1][0], dp[n-1][1])<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}
