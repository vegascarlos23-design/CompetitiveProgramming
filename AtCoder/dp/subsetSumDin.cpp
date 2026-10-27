#include <bits/stdc++.h>

using namespace std;
const long long MOD = 998244353;

void solve() {
	int q,x; cin>>q>>x;

	string s;
	int c;
	bool posi = 0;

	vector<long long> dp(x+1);
	dp[0] = 1;

	while(q--) {
		cin>>s>>c;
		if (s[0] == '+') posi = 1;	
		else posi = 0;
		
		if (posi) {
			for(int k = x; k >= c; k--) {
				dp[k] = (dp[k] + dp[k - c]) % MOD;	
			}
		} else {
			for (int k = c; k <= x; k++) {
				dp[k] =  (dp[k] - dp[k - c] + MOD) % MOD;
			}
		}
		cout<<dp[x]<<endl;
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
