#include <bits/stdc++.h>

using namespace std;

vector<int> divs(1e6+1);


void precompute() {
	for(int i = 1; i <= 1e6; i++) {
		for(int mult = i; mult <= 1e6; mult += i) {
			divs[mult]++;
		}
	}
}

void solve() {
	int x; cin>>x;
	
	cout<<divs[x]<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	precompute();
	int t = 1;
	cin>>t;
	
	while(t--) {
		solve();
	}

	return 0;
}
