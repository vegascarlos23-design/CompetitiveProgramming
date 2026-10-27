
#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s; cin>>s;
	long long n = s.size();

	long long cur = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		if (s[i] == '-') cur--;
		else cur++;

		if (cur < 0) { 
			ans += (i+1);
			cur = 0;
		}	
	}
	ans += n;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}
