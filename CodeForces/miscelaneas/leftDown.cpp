#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long a,b,k; cin>>a>>b>>k;

	if (a <= k && b <= k) {
		cout<<1<<endl;
		return;
	}

	long long g = __gcd(a,b);
	if (a/g <= k && b/g <= k) {
		cout<<1<<endl;
		return;
	}

	cout<<2<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	cin >> t;
	while(t--)  solve();
	return 0;
}
