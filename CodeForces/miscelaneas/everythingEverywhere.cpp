#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin>>n;
	vector<int> v(n); for(auto &x : v) cin>>x;

	int ans = 0;
	for(int i = 0; i < n-1; i++) {
		if (abs(v[i] - v[i+1]) == __gcd(v[i], v[i+1])) ans++;		
	}

	cout<<ans<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	cin >> t;
	while(t--)  solve();
	return 0;
}
