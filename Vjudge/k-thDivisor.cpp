#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n,k; cin>>n>>k;

	vector<long long> div;
	for(long long i = 1; i*i <= n; i++) {
		if (!(n % i)) {
			div.push_back(i);	
		}
	}

	long long tam = div.size();
	long long r = sqrtl(n);
	bool square = (r*r == n);
	
	long long total = 2* tam - square;

	if (k > total) {
		cout<<-1<<endl;
		return;
	}
	if (k <= tam) {
		cout<<div[k-1]<<endl;
		return;
	}
	
	cout<< n / div[total - k] << endl;
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
