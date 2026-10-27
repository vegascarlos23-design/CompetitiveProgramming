#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin>>n;
	vector<int> a(n); for(auto &x : a) cin>>x;
	
	for (int mask = 0; mask < (1<<n); mask++) {
		int c = 0;
		for(int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				c += a[i];	
			} else {
				c -= a[i];
			}
		}
		if (c == 0 || abs(c) % 360 == 0) {
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	//cin >> t;
	while(t--)  solve();
	return 0;
}
