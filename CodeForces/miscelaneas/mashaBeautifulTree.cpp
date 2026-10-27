#include <bits/stdc++.h>

using namespace std;

int ans = 0;

void divide(int l, int r, vector<int>& v) {
	if (l == r) {
		return;	
	}
	int m = (l + r)/2;

	divide(l,m,v);
	divide(m+1,r,v);

	int mxl = -1, mxr = -1;
	for(int i = l; i <= m; i++) {
		mxl = max(mxl,v[i]);
	}

	for(int i = m+1; i <= r; i++) {
		mxr = max(mxr,v[i]);
	}

	if (mxl > mxr) {
		ans++;
		for(int i = l; i <= m; i++) {
			swap(v[i], v[i + (m-l+1)]);
		}
	}
}


void solve(){
	int n; cin>>n;
	ans = 0;
	vector<int> v(n); for(auto &x : v) cin>>x;

	divide(0,n-1,v);
	if (is_sorted(v.begin(), v.end())) cout<<ans<<endl;
	else cout<<-1<<endl;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	cin >> t;
	while(t--)  solve();
	return 0;
}
