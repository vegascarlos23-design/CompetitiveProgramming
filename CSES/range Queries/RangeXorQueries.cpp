#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n, q; cin>>n>>q;

	vector<long long> a(n); 
	vector<long long> prfXor(n+1);
	
	for(int i = 1; i <= n; i++) {
		cin>> a[i-1];
		prfXor[i] = prfXor[i-1] ^ a[i-1];
	}

	while(q--) {
		int l,r; cin>>l>>r;

		cout<< (prfXor[r] ^ prfXor[l-1]) <<endl;
	}
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
