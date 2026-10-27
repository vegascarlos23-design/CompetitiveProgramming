#include <bits/stdc++.h>

using namespace std;

const long long MOD  = 1e9 + 7;

void solve() {
	int n; cin>>n;
	long long ans = 1;
	for (int i = 1; i <= n; i++)  {
		ans = (ans << 1) % MOD;
	}
	cout<<ans<<endl;
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
