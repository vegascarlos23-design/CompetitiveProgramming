#include<bits/stdc++.h>
using namespace std;

void solve() {
	int a,b,c; cin>>a>>b>>c;

	int ans = 0;
	for(int i = 1; i*i <= c; i++) {
		if (c % i == 0) {
			if (i <= b && i>= a) ans++;
			if (c/i != i && c/i <= b && c/i >= a) ans++;
		}	
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
