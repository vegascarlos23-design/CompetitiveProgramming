#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long a,b; cin>>a>>b;
	if (b % a) {
		cout<<lcm(a,b)<<endl;
	} else {
		cout<< b * b/a<<endl;
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
