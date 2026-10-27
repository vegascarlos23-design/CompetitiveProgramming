
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin>>n;
	vector<long long> fst(7,-1);

	fst[0] = 0;

	long long sum = 0, ans = 0;

	for(int i = 1; i <= n; i++) {
		long long x; cin>>x;

		sum += x;
		int r = sum % 7;

		if (fst[r] == -1) {
			fst[r] = i;
		} else {
			ans = max(ans , i - fst[r]);
		}
	}
	cout<<ans<<endl;
}

int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}
