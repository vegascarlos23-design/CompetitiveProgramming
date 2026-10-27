#include <bits/stdc++.h>
using namespace std;

bool prop(vector<int>& v , int k, int m){
    long long sum = 0;
    int n = v.size();

    for (int i = 0; i < m; i++) sum += v[i];
    if (sum <= k) return 1;

    for (int i = m; i < n; i++) {
        sum += v[i] - v[i - m];
        if (sum <= k) return 1;
    }
    return 0;
}

void solve(){
    long long n,k; cin>>n>>k;
    vector<int> v(n);
    for (int& x: v) cin>>x;
    int l = 0, r=n+1;
    while (r-l > 1){
        int m = (l+r)/2;
        if (prop(v,k,m)) l = m;
        else r = m;
    }
    cout<<l;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}