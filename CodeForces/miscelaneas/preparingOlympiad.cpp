#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long n,l,r,x; cin>>n>>l>>r>>x;

	vector<long long> v(n); for(auto &c: v) cin>>c;

	long long ans = 0;
	for(int mask = 0; mask < (1 << n); mask++) {
		long long sum = 0;
		long long mxVal = -1, mnVal = 1e18;
		for(int i = 0; i<n; i++) {
			if (mask & (1<<i)) {
				sum += v[i];
				mxVal = max(mxVal, v[i]);
				mnVal = min(mnVal, v[i]);
			}
		}
		
		if (sum >= l && sum <= r && (mxVal - mnVal >= x)) {
			ans++;			
		}
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
