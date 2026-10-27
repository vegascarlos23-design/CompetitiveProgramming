#include <bits/stdc++.h>

using namespace std;

void solve() {
	int t,a,b; cin>>t>>a>>b;

	vector<bool> dp0(t+1), dp1(t+1);
	dp0[0] = 1;

	for(int i = 0; i < t; i++) {
		if (!dp0[i]) continue;
		if (i + a <= t) dp0[i+a] = dp0[i];
		if (i + b <= t) dp0[i+b] = dp0[i];
	}

	for(int i = 1; i < t; i++) {
		if (!dp0[i]) continue;
		dp1[i/2] = dp0[i];
	}

	for(int i = 0; i < t; i++) {
		if (!dp1[i]) continue;
		if (i + a <= t) dp1[i+a] = dp1[i];
		if (i + b <= t) dp1[i+b] = dp1[i];
	}

	int i = t;
	while(i) {
		if (dp0[i] || dp1[i]) {
			cout<<i<<endl;
			return;
		}
		i--;
	}
}

int main() {
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}
