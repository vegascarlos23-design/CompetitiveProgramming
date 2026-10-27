#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e15;

long long ps(long long x, long long d) {
	int cnt = 0;
	if (x == 0) return cnt;

	while (true) {
		if (x % d == 0) {
			cnt++;
			x /= d;
		} else {
			break;
		}
	}	
	return cnt;
}

void solve(){
	int n; cin>>n;
	vector<vector<long long>> g(n,vector<long long>(n));


	int i0 = -1, j0 = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n;j++) {
			cin >> g[i][j];
		       	
			if (g[i][j] == 0) {
				i0 = i;
				j0 = j;
			}	
		}
	}

	
	vector<vector<long long>> dp2(n, vector<long long> (n , INF)),dp5(n, vector<long long> (n , INF));

	vector<vector<char>> path2(n, vector<char>(n)), path5(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long twos , fives;

			if (g[i][j] == 0) {
				twos = INF;
				fives = INF;
			} else {
				twos = ps(g[i][j] , 2);
				fives = ps(g[i][j] , 5);
			}

			if (i == 0 && j == 0) {
				dp2[i][j] = twos;
				dp5[i][j] = fives;
				continue;
			}

			if (i - 1 >= 0) {
				dp2[i][j] = dp2[i-1][j] + twos;
				path2[i][j] = 'D';

			}

			if (j - 1 >= 0 && dp2[i][j-1] + twos < dp2[i][j]) {
				dp2[i][j] = dp2[i][j-1] + twos;
				path2[i][j] = 'R';
			}

			if (i - 1 >= 0) {
				dp5[i][j] = dp5[i-1][j] + fives;
				path5[i][j] = 'D';

			}

			if (j - 1 >= 0 && dp5[i][j-1] + fives < dp5[i][j]) {
				dp5[i][j] = dp5[i][j-1] + fives;
				path5[i][j] = 'R';
			}

		}
	}
	
	long long ans = min(dp2[n-1][n-1],dp5[n-1][n-1]);
	
	if (i0 != -1 && ans > 1) {
		cout<<1<<endl;

		string path = "";

		path += string(i0, 'D');
		path += string(j0, 'R');

		path += string(n-1-i0, 'D');
		path += string(n-1-j0, 'R');

		cout<<path<<endl;
		return;
	}

	cout<<ans<<endl;

	vector<vector<char>> &path = (dp2[n-1][n-1] < dp5[n-1][n-1] ? path2 : path5);

	string res = "";
	int i = n-1, j = n-1;

	while(i != 0 || j != 0) {
		char c = path[i][j];
		res += c;

		if (c == 'D') i--;
		else j--;
	}	

	reverse(res.begin(), res.end());
	cout<<res<<endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1; 
	//cin >> t;
	while(t--)  solve();
	return 0;
}
