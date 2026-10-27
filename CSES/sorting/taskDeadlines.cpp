#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin>>n;
	vector<long long> v(n);

	long long total = 0;
	for(int i = 0; i < n; i++) {
		long long a,b; cin>>a>>b;
		v[i] = a;
		total += b;
	}

	sort(v.rbegin(), v.rend());
	
	long long dif = 0;
	for(int i = 0; i < n; i++) {
		dif += v[i]*(i+1);
	}

	cout<< total - dif << endl;
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
