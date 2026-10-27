#include <bits/stdc++.h>

using namespace std;

void solve() {
	int l, r; cin>>l>>r;
	
	int mxXor = 0;
	for(int i = l; i <= r; i++) { 
		for(int j = i; j <= r; j++) {
			int curXor = (i ^ j);
			mxXor = max(mxXor, curXor);
		}
	}	

	cout<<mxXor<<endl;
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
