#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long n; cin>>n;
	vector<long long> a(n); for(auto &x : a) cin>>x;

	if (n == 1) {
		cout<<1<<endl;
		return;
	}
	
	long long mx = *max_element(a.begin(), a.end());
	long long g = 0;
	for(auto &x : a) {
		g = __gcd(g,mx - x);
	}

	long long ans = 0;

	for(auto &x : a) {
		ans += (mx - x) / g;
	}

	set<long long> st(a.begin(), a.end());

	long long k = 1;

	while(st.count(mx - k*g)) {
		k++;
	}

	ans += k;
	cout<<ans<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	cin >> t;
	while(t--)  solve();
	return 0;
}
