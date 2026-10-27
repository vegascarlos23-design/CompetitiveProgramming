#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n; cin>>n;
    ll k; cin>>k;
    vector<int> v(n);
    for (auto& x : v) cin>>x;

    int left = 0, right = 0;
    ll sum = 0, msum = 0;
    
    while (left<n) {
        right = max(right, left);
        while (right<n && sum + v[right] <= k) {
            sum += v[right];
            right++;
        }
        msum = max(msum,sum);
        if (left != right) sum -= v[left];
        left++;
    }
    cout<<msum;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1; 
    //cin >> t;
    while(t--)  solve();
    return 0;
}