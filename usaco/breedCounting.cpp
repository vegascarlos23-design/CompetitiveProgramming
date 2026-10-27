#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n,q; cin>>n>>q;

	vector<int> a(n); for(auto &x : a) cin>>x;
	vector<int> pre1(n), pre2(n), pre3(n);

	
	pre1[0] = (a[0] == 1);
	pre2[0] = (a[0] == 2);
	pre3[0] = (a[0] == 3);
	
	for(int i = 1; i < n; i++) {
		pre1[i] = pre1[i-1] + (a[i] == 1);
		pre2[i] = pre2[i-1] + (a[i] == 2);
		pre3[i] = pre3[i-1] + (a[i] == 3);
	}

	while(q--) {
		int l,r; cin>>l>>r;
		l--; r--;
		int v1,v2,v3;
		v1 = pre1[r]; if(l-1 >= 0) v1 -= pre1[l-1];		
		v2 = pre2[r]; if(l-1 >= 0) v2 -= pre2[l-1];		
		v3 = pre3[r]; if(l-1 >= 0) v3 -= pre3[l-1];
		cout<<v1<<" "<<v2<<" "<<v3<<endl;		
	}
}

int main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}
