#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long n,q; cin>>n>>q;

	vector<long long> a(n); for(auto &x : a) cin>>x;
	vector<long long> pref(n);

	pref[0] = a[0];
	for(int i = 1; i < n; i++) {
		pref[i] = pref[i-1] + a[i];
	}
	

	while(q--) {
		long long l,r,k; cin>>l>>r>>k;
		l--; r--;
		long long sum = pref[n-1] - pref[r];
		if (l - 1 >= 0) sum += pref[l-1];
		long long taml = r-l+1;
		cout<< ((taml*k + sum) & 1LL ? "YES" : "NO")<<endl;
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
