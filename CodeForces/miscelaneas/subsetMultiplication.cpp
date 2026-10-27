#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin>>n;
	vector<long long> a(n); for(auto &x: a) cin>>x;

	long long g = 0;
	long long l = 1;

	for(int i = n-1; i >= 0; i--) {
		g = __gcd(g,a[i]);
		l = lcm(l,a[i] / g);
	}
	cout<<l<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	cin >> t;
	while(t--)  solve();
	return 0;
}
