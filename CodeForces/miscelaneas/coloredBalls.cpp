#include <bits/stdc++.h>

using namespace std;
const long long MOD = 998244353;

void solve(){
	int n; cin>>n;
	vector<long long> a(n); for(auto &x : a) cin>>x;

	sort(a.begin(), a.end());

	vector<long long> dp (5001);
	dp[0] = 1;

	long long sum = 0, x = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		x = a[i];
		for (int s = 0; s <= sum; s++) {
			ans = (ans + (dp[s] * max(x, (s + x + 1) / 2)) % MOD) % MOD;
		}

		for (int s = sum; s >= 0; s--) {
			dp[s + x] = (dp[s + x] + dp[s]) % MOD;
		}

		sum = (sum + x);
	}
	cout<<ans<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	//cin >> t;
	while(t--)  solve();
	return 0;
}
