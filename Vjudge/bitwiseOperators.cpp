#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k; cin>>n>>k;
	
	int mxAnd = 0,mxOr = 0, mxXor = 0;
	for(int i = 1; i <= n; i++) { 
		for(int j = i+1; j <= n; j++) {
			int curAnd = (i & j), curOr = (i | j), curXor = (i ^ j);
			if (curAnd < k) mxAnd = max(mxAnd, curAnd);
			if (curOr < k) mxOr = max(mxOr, curOr);
			if (curXor < k) mxXor = max(mxXor, curXor);
		}
	}	

	cout<<mxAnd<<endl<<mxOr<<endl<<mxXor;
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
