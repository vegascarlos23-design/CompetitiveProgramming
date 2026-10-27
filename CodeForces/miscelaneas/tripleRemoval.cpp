
#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n,q; cin>>n>>q;

	vector<int> a(n); for(auto &x : a) cin>>x;

	vector<int> prAdj(n+1), pr1(n+1), pr0(n+1);

	for(int i = 1; i <= n; i++) {
		if (i > 1) prAdj[i] = prAdj[i-1] + (a[i-1] == a[i-2]);
	       	pr0[i] = pr0[i-1] + (a[i-1] == 0);
		pr1[i] = pr1[i-1] + (a[i-1] == 1);
	}

	while(q--) {
		int l,r; cin>>l>>r;
		int ans = 0;
		if (( (pr0[r] - pr0[l-1]) % 3 == 0) && ( (pr1[r] - pr1[l-1]) % 3 == 0)) {
			ans = (r -  l + 1) / 3;
			if (prAdj[r] - prAdj[l] == 0) ans++;
			cout<<ans<<endl;
		} else {
			cout<<-1<<endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	cin >> t;
	while(t--)  solve();
	return 0;
}
