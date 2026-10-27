#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n,m,k; cin>>n>>m>>k;
	
	if (m%k != 0) {
		int cur = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cout<< cur % k + 1 << " ";
			       	cur++;	
			}
			cout<<'\n';
		}
		return;
	}
	
	bool ok1 = 1;
	vector<int> last(m+1);

	for(int i = 0; i < m ; i++) {
		last[i+1] = i % k + 1;
	}	

	for(int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout<< (last[j-1] % k) + 1 << " ";
			last[j-1] = (last[j-1] % k) + 1;
		}
		cout<<'\n';
	} 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}
