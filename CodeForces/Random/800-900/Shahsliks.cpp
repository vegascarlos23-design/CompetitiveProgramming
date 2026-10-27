#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k,a,b,x,y;  cin>>k>>a>>b>>x>>y;
    auto solve = [&](int k, int a, int b, int x, int y) {
        int res = 0;
        res += max((k-a+x)/x , 0);
        k -= max((k-a+x)/x, 0)*x;
        res += max((k-b+y)/y , 0);
        return res;
    };
    cout<<max(solve(k,a,b,x,y),solve(k,b,a,y,x))<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}