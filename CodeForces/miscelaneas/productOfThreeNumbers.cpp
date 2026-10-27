#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long n; cin>>n;

	set<long long> ans;
	for (long long i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			ans.insert(i);
			n /= i;
			break;
		}
	}	

	for(long long i = 2; i*i <= n; i++) {
		if (n % i == 0 && !ans.count(i)) {
			ans.insert(i);
			n /= i;
			break;
		}
	}

	if (ans.size() < 2 || ans.count(n) || n == 1) {
		cout<< "NO" << endl;
	} else {
		ans.insert(n);
		cout<< "YES" << endl;
		for( auto x: ans) cout << x << " ";
		cout<<endl;
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
