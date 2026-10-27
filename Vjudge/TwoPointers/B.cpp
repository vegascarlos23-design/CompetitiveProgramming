#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n,k; cin>>n>>k;
    vector<int> v(n);
    for (auto& x : v) cin>>x;

    int left = 0, right = 0;
    ll sum = 0;
    int mxlen = 0;
    ll mink = LLONG_MAX;
    
    while (left<n) {
        right = max(right, left);
        while (right<n && sum + v[right] <= k) {
            sum += v[right];
            right++;
        }
        int len = right - left;
        if (len > mxlen) {
            mxlen = len;
            mink = sum;
        }
        else if (len == mxlen) {
            mink = min(mink,sum);
        }
        
        if (left != right) sum -= v[left];
        left++;
    }
    cout<<mink<<" "<<mxlen<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    cin >> t;
    while(t--)  solve();
    return 0;
}