#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    set<long long> s;
    int l = 0, r = 0, mx = 0;

    while (r<n) {
        while (s.find(a[r]) != s.end()) {
            s.erase(a[l]);
            l++;
        }
        s.insert(a[r]);
        mx = max(mx, r-l+1);
        r++;
    }

    cout <<mx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}