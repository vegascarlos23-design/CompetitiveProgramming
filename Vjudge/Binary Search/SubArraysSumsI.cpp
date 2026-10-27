#include <bits/stdc++.h>
using namespace std;

bool prop(int m, vector<long long>& v, long long x){
    int n = v.size() , l = 0 , c = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i]; 
        if(sum > x) {
            while(sum > x) {
                sum -= v[l];
                l++;
            }
        }
        if(sum == x) c++;
        if (c == m) return 1;
    }
    return 0;
}

void solve(){
    int n; cin>>n;
    long long x; cin>>x;
    vector<long long> v(n);
    for(auto& x:v) cin>>x;

    int l = 0, r = INT_MAX;
    while (r-l > 1){
        int m = (l+r)/2;
        if (prop(m,v,x)) l = m;
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