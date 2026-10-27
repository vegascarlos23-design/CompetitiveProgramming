#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long n; cin>>n;
	vector<long long> a(n); for(auto &x : a) cin>>x;

	vector<long long> pre1(n+1),pre2(n+1);

	for(int i = 1; i <= n; i++) {
		pre1[i] = pre1[i-1] + a[i-1];
	}
	sort(a.begin(), a.end());

	for(int i = 1; i <= n; i++) {
		pre2[i] = pre2[i-1] + a[i-1];
	}

	long long q; cin>>q;
	while(q--) {
		long long ti,l,r; cin>>ti>>l>>r;
	       	if (ti == 1) {
			cout<<pre1[r] - pre1[l-1];
		} else {
			cout<<pre2[r] - pre2[l-1];
		}
		cout<<endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	//cin >> t;
	while(t--)  solve();
	return 0;
}
