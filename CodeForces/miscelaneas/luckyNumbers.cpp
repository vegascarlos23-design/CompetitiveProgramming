#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s; cin>>s;
	int n = s.size();

	string ans = "999999999";
	for(int mask = 0; mask < (1 << n); mask++) {
		string cur = "";
		int c4 = 0, c7 = 0;
		for(int i = 0; i<n; i++) {
			if (mask & (1<<i)) {
				cur += '4';
			       	c4++;	
			} else {
				cur += '7';
				c7++;
			}
		}
		if (c4 == c7 && cur >= s) {
			ans = min(ans, cur);
		}
	}

	if (ans == "999999999") {
		ans = "";
		if (!(n & 1)) n += 2; 	

		for (int i = 0; i < (n + 1)/2; i++) ans += '4';
		for (int i = 0; i < (n+1)/2; i++) ans += '7';
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
