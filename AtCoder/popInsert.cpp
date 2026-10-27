#include <bits/stdc++.h>

using namespace std;

int ansF(string s, char c) {
	int n = s.size();
	
	int cnt = 0;
	int cur = 0, mxl = -1;
	for(int i = 0; i < n; i++) {
		if (s[i] == c) {
			cnt++;
			cur++;
			mxl = max(mxl ,cur);
		} else {
			cur = 0;
		}
	}
	return (n - cnt) + (cnt - mxl) * 2;
}
void solve() {
	int n; cin>>n;
	string s; cin>>s;
	
	int ans = min( ansF(s,'0'), ansF(s,'1'));
	cout<<ans<<endl;


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
