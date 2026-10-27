#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n,x; cin>>n>>x;

	vector<long long> v(n); for(auto &x : v) cin>>x;
	sort(v.begin(),v.end());

	int l = 0, ans = 0;
	
	for(int i = n-1; i >= 0; i--) {
		if (i < l) break;
		if (v[i] + v[l] <= x) l++;
		ans++;
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
