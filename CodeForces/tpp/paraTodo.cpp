#include <bits/stdc++.h>

using namespace std;

vector<long long> primes;

void criba() {
	int lim = 1e6;
	vector<bool> comp(lim + 1);

	for(long long i = 2; i <= lim; i++) {
		if (!comp[i]) {
			primes.push_back(i);
			for (long long j = i*i; j <= lim; j += i) {
				comp[j] = 1;
			}	
		}
	}
}

void solve() {
	long long n; cin>>n;
	long long d = 1,cnt = 0,mn = LLONG_MAX;
	bool has2 = 0;

	for(long long p : primes) {
		if (p*p > n) break;
		if (n%p != 0) continue;

		int e = 0;
		while (n % p == 0) {
			n/= p;
			e++;
		}

		if (e >= 2) {
			long long c = 1;
			for(int i = 0; i < (e/2) * 2; i++) c *= p;
			cnt++;
			d *= c;
			if (p == 2) has2 = 1;
			else mn = min(mn, c);
		}
	}

	if (n > 1) {
		long long r = sqrtl(n);
		while(r*r > n) r--;
		while((r+1) * (r+1) <= n) r++;
		if (r*r == n) {
			cnt++;
			d *= n;
			mn = min(mn, n);
		}
	}

	if (!has2) {
		cout<<-1<<'\n';
		return;
	}

	if (cnt % 2 == 1) {
		if (mn == LLONG_MAX) {
			cout<<-1<<'\n';
			return;
		}

		d /= mn;
		cnt--;
	}
	if (cnt < 2) cout <<-1<<'\n';
	else cout<<d<<'\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin>>t;
	criba();
	while(t--) {
		solve();
	}

	return 0;
}
