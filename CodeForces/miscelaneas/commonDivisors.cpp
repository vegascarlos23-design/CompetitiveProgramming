#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin>>n;
	vector<long long> v(n); for(auto &x: v) cin>>x;

	long long g = accumulate(v.begin(), v.end(), 0, [](long long a, long long b) {
				return gcd(a,b);
			});
	long long ans = 0;
	for (long long i = 1; i*i <= g; i++) {
		if (g%i == 0) {
			ans++;
			if (g / i != i) ans++;
		}	
	}
	cout<<ans<<endl;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	//cin >> t;
	while(t--)  solve();
	return 0;
}
